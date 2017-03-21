class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> DU(numCourses,0);//存储每个节点的入度
        vector<bool> used(numCourses,false);//表示每个节点是否已在该图中被删除
        vector<vector<int>> Link(numCourses,vector<int>());
        for(auto x:prerequisites)
        {
            ++DU[x.first];//若为一有向边的终点，则将其入度加一
            Link[x.second].push_back(x.first);
        }
        int cnt(0);
        while(1)
        {
            bool st = false;//记录当前是否能找到一个入度为0的点
            for(int i=0;i<numCourses;i++)
                if(DU[i]==0&&!used[i])//拓展节点
                {
                    st = true;
                    cnt++;
                    used[i] = true;
                    for(auto x:Link[i]) DU[x]--;
                }
            if(!st) break;//无法找到则跳出循环
        }
        return cnt==numCourses;//判断整张图中是否所有节点都已被删除
    }
};
