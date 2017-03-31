class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int now = 0;
        if (A[2] - A[1] == A[1] - A[0]) now = 1; 
        int ans = now;
        for (int i = 3; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) ++now;
            else now = 0;
            ans += now; 
        }
        return ans;
    }
};