class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty()) return 0;
        unordered_map<long long, int> ma[A.size()];
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
            for(int j = i-1; j >= 0; j--){
                if(A[i] == A[j]) continue ;
                long long d = (long long)A[i]-A[j];
                if(ma[j].find(d) != ma[j].end()){
                    ans += ma[j][d];
                    ma[i][d] += ma[j][d]+1;
                }
                else ma[i][d]++;
            }
        unordered_map<int, int> cal;
        for(auto x: A) cal[x]++;
        for(auto x: cal) {
            int n = x.second;
            if(n > 2) ans += (1LL<<n)-n-1-n*(n-1)/2;
        }
        return ans;
    }
};
