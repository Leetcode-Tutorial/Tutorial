class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> DU(numCourses,0);//存储每个节点的入度
        vector<bool> used(numCourses,false);//表示每个节点是否已在该图中被删除
        vector<int> Q;//入度为0的待处理节点加入队列之中
        vector<vector<int>> Link(numCourses,vector<int>());
        vector<int> ans;
        for(auto x:prerequisites)
        {
            ++DU[x.first];//若为一有向边的终点，则将其入度加一
            Link[x.second].push_back(x.first);
        }
        int cnt(0);
        for(int i=0; i<numCourses; i++)
            if(!DU[i]) Q.push_back(i);//将入度为0的点压入容器中
        while(!Q.empty())
        {
            cnt++;
            int x = Q.back();
            Q.pop_back();
            ans.push_back(x);
            for(auto i:Link[x])//将结点x所有连接到的点的入度减1
            {
                DU[i]--;
                if(!DU[i]) Q.push_back(i);
            }
        }
        if(cnt!=numCourses) ans.clear();//判断整张图中是否所有节点都已被删除
        return ans;
    }
};
