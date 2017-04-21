class Solution2 {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        map<string, unordered_map<string,double>> F;//存储当前图的联系情况
        unordered_map<string,bool> visited;
        for(int i=0; i<equations.size(); i++)
        {
            string x = equations[i].first;
            string y = equations[i].second;
            Addlink(x, y, values[i],F);
            if(values[i]!=0)//判断当前比例是否非0，否则可以建立一条合法的反向边
            Addlink(y , x, 1.0/values[i],F);
        }
        for(auto x:F)
        {
            Addlink(x.first, x.first, 1.0,F);//每个节点建立一条自己到自己的边
            visited[x.first] = false;
        }
        int cnt = 0;
        for(auto x:F)
            if(!visited[x.first])//尚未遍历过就建立一个新的联通块
            {
                va[x.first] = make_pair(++cnt,1.0);
                dfs(x.first, cnt, F, visited);
            }
        for(auto i:queries)
        {
            pair<int,double> pair_x = va[i.first];
            pair<int,double> pair_y = va[i.second];
            if(pair_x.first != pair_y.first||pair_x.second == 0)    ans.push_back(-1.0);//如果两点不在一个联通块之内，则无法确定比例关系
            else ans.push_back(pair_y.second/pair_x.second);
        }
        return ans;
    }
    void Addlink(const string &x, const string &y, const double &va, map<string, unordered_map<string,double>> &F)
    {
        if(F.find(x) == F.end())
            F[x]=unordered_map<string,double>();
        F[x][y]=va;
    }
    void dfs(const string cur,const int color,map<string, unordered_map<string,double>> &F,unordered_map<string,bool> &visited)
    {
        visited[cur] = true;
        double tmp = va[cur].second;
        for(auto i:F[cur])
            if(!visited[i.first]){
                va[i.first] = make_pair(color, tmp * i.second);
                dfs(i.first, color, F, visited);
            }
    }
private:
            map<string, pair<int, double>> va;
};
