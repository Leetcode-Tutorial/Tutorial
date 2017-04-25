class Solution {
public:
int findMaxForm(vector<string>& strs, int m, int n) {
//这里选最多，也可以转化为0,1背包来做
//vector<vector<int,int> >dp(m+1, vector<int>(n+1,0));
//初始化一个二维数组,一开始初始化就全为0
int dp[m+1][n+1];
memset(dp,0,sizeof(dp)); //如果你不给它初始化，那么它就是随机的
int len = strs.size(),i,j;
 
for(i = 0;i<len;i++)
{
int zeros = 0,ones = 0;
string temp = strs[i];
for(j = 0;j < temp.length();j++)
{
if(temp[j]=='1')
ones++;
else
zeros++;
}
//有一个处理边界就是m小于zeros个数或者w小于ones个数怎么办
//printf("%d,%d\n",m,n);
for(int k = m;k>=zeros;k--) //一定要逆向走
{
for(int w = n;w>=ones;w--) //这是从右底部一直走
{
//这个dp[k][w]实际上是dp[i-1][k][w]就是没有选择第i个
dp[k][w] = max(dp[k][w],dp[k-zeros][w-ones]+1); //这个dp代表数量
}
}
}
return dp[m][n];
}
};