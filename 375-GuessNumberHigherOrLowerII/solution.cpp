class Solution {
public:
    int getMoneyAmount(int n) {
        int min_sum[n + 2][n + 2];
        memset(min_sum, 0, sizeof(min_sum));
        // iterate the length of subarray
        for (int l = 1; l <= n; l++)
            // iterate the beginning of subarray
            for (int i = 1; i + l - 1 <= n; i++){
                // calculate the end of subarray based on the length of subarray
                int j = i + l - 1;
                // if l == 1(i.e. i==j), it means the penalty of subarray is zero
                if (i == j) min_sum[i][j] = 0;
                else{
                    min_sum[i][j] = (1 << 30);
                    // iterate the first picked number in subarray
                    for (int k = i; k <= j; k++)
                        min_sum[i][j] = min(min_sum[i][j], max(min_sum[i][k - 1], min_sum[k + 1][j]) + k);
                }
            }
        return min_sum[1][n];
    }
};
