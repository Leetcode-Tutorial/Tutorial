class Solution {
public:
    string getPermutation(int n, int k) {
        int a[11], A[11];
        int left = n; //还剩下多少数
        bool vis[11] = {0};
        A[0] = 1; for (int i = 1; i <= n; i++) A[i] = A[i-1]*i;
        
        for (int i = 1; i <= n; i++) { //当前在放第i位的数
            for (int j = 1; j <= n; j++) { //判断应该放第j大的
                if (j*A[left-1] >= k) { //找剩下的数中第j大的
                    int cnt = 0;
                    for (int id = 1; id <= n; id++) if (!vis[id]) {
                    	cnt++;
                    	if (cnt == j) {
                    		k -= (j-1)*A[left-1];
                    		a[i] = id, vis[id] = 1, left--;
                    		break;
                    	}
                    }
                    break;
                }
            }
        }
        string ans = ""; 
        for (int i = 1; i <= n; i++) ans += (char) (a[i]+'0');
        return ans;
    }
};
