class Solution {
public:
    int fa[205];
    bool vis[205];
    int find (int x) {
        return fa[x] == x ? fa[x] : fa[x] = find (fa[x]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size ();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) fa[i] = i, vis[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (M[i][j]) {
                int fa1 = find (i), fa2 = find (j);
                if (fa1 != fa2) //如果两个点不在同一个联通分量，直接合并
                    fa[fa1] = fa2;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = find (i);
            if (!vis[tmp]) ans++, vis[tmp] = 1;
        }
        return ans;
    }
};
