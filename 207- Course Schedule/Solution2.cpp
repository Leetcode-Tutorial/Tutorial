class Solution2 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses,false);//表示每个节点已被访问过
        vector<bool> onpath(numCourses,false);//记录一个节点是否在当前的DFS路径上
        vector<vector<int>> Link(numCourses,vector<int>());
        for(auto x:prerequisites)
        {
            Link[x.second].push_back(x.first);
        }
        for(int x=0; x<numCourses; x++)
            if(!visited[x]&&dfs(x, numCourses, Link, visited, onpath))//如果当前节点未被访问过则对其进行搜索；如果发现环，则无解
                return false;
        return true;
    }
    bool dfs(int x,int numCourses, vector<vector<int>> &Link,vector<bool> &visited, vector<bool> &onpath)
    {
        if(visited[x]) return false;
        visited[x] = onpath[x] = true;//标记其已经访问过
        for(auto i:Link[x])
            if(onpath[i]||dfs(i, numCourses, Link, visited, onpath))
            return true;
        onpath[x] = false;//进行一次回溯
        return false;
    }
};
