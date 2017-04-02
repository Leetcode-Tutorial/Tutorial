class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        Height.assign(n,0);
        fa.assign(n,-1);
        Max_son.assign(n, make_pair(0,0));//记录一个树结点向下的最长链
        Sec_son.assign(n, make_pair(0,0));//记录一个树结点向下的次长链
        Link.assign(n,vector<int>(0,0));
        for(auto i:edges)//根据每点建立连接
        {
            int x = i.first;
            int y = i.second;
            Link[y].push_back(x);
            Link[x].push_back(y);
        }
        Init_height(0,-1);
        cal_height(0,0);
        int cur_max(n);
        for(int i=0; i<n; i++)
        {
            if(Height[i]<cur_max)
            {
                cur_max = Height[i];
                ans.clear();
            }
            if(Height[i]==cur_max)
                ans.push_back(i);
        }
        return ans;
    }
private:
    void Init_height(int no,int no_fa)//no_fa用来记录父节点，以防重复访问,初始化各个节点的子树的最大高度
    {
        fa[no] = no_fa;
        for(auto x:Link[no])
        {
            if(x==no_fa) continue;
            Init_height(x, no);
            if(Height[x]>Max_son[no].second)//更新最长以及次长链
            {
                Sec_son[no] = Max_son[no];
                Max_son[no] = make_pair(x, Height[x]);
                continue;
            }
            if(Height[x]>Sec_son[no].second)
                Sec_son[no] = make_pair(x, Height[x]);
        }
        Height[no] = Max_son[no].second + 1;
    }
    void cal_height(int no, int Height_from_fa)
    {
        Height[no] = max(Height[no], Height_from_fa);
        for(auto x:Link[no])
        {
            if(x == fa[no]) continue;
            if(x==Max_son[no].first)
                cal_height(x, max(Sec_son[no].second+1, Height_from_fa)+1);
            else cal_height(x, max(Max_son[no].second+1, Height_from_fa)+1);
        }
    }
    vector<pair<int,int>> Max_son;
    vector<pair<int,int>> Sec_son;
    vector<int> ans;
    vector<int> Height;
    vector<int> fa;
    vector<vector<int>> Link;
};
