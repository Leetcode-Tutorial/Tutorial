class Solution {
public:
    int numSquares(int n) {
        static vector<int> cntPerfectSquares{0};//n=0时，数量为0，充当初始值。
        while(cntPerfectSquares.size()<=n){//cntPerfectSquares.size()==n+1时，说明正整数n的结果已经找到。
            int cur = cntPerfectSquares.size();//当前的正整数
            int cur_count = INT_MAX;//当前正整数的结果
            for(int i=1; i*i<=cur; i++){//遍历所有小于或等于当前正整数的完全平方数
                cur_count=min(cur_count, cntPerfectSquares[cur-i*i]+1);//更新最小值
            }
            cntPerfectSquares.emplace_back(cur_count);//当前正整数的结果已经找到，记录下来
        }
        return cntPerfectSquares[n];
    }
};
