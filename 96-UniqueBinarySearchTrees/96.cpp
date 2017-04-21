class Solution {
public:
    int numTrees(int n) {
        //���ȿ��������ʼ����
        if(n==1||n==0)
            return 1;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;                         //���Եߵ�
        dp[0] = 1;

        for(int i = 3;i<=n;i++)            //��ÿһ��dp[n]��
        {
            for(int j = 1;j<=i;j++)         //���в��
            {
                dp[i] += dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }
};
