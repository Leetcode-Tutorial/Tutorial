class Solution {
    #define st first
    #define nd second
    #define pii pair<int, int>
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false) );
        vector<vector<int>> h = heightMap;

        auto cmp = [&heightMap](pii a, pii b) { return heightMap[a.st][a.nd] > heightMap[b.st][b.nd];};
        priority_queue<pii, vector<pii>, decltype(cmp)> Q(cmp);
        for(int i = 0; i < n; i++){
            Q.push({0, i}); vis[0][i] = true;
            Q.push({m-1, i}); vis[m-1][i] = true;
        }
        for(int i = 1; i < m-1; i++){
            Q.push({i, 0}); vis[i][0] = true;
            Q.push({i, n-1}); vis[i][n-1] = true;
        }
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, ans = 0;
        while(!Q.empty()){
            auto now = Q.top();
            Q.pop();
            for(int i = 0; i < 4; i++){
                int x = now.st+dx[i], y = now.nd+dy[i];
                if(x < 0||x >= m||y < 0||y >= n||vis[x][y]) continue ;
                vis[x][y] = true;
                if(h[x][y] <= h[now.st][now.nd])
                    h[x][y] = h[now.st][now.nd], ans += h[x][y]-heightMap[x][y];
                Q.push({x, y});
            }
        }
        return ans;
    }
};
