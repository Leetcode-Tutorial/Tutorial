class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0, temp = n;
        if(n <= 0) return ans;
        vector<int> ve;
        while(temp){//分隔出各个数
            ve.push_back(temp%10);
            temp /= 10;
        }
        for(int i = 0, pre = n/10, suf = 0, pow = 1; i < ve.size(); i++){
            //从低位往高位统计
            //如果该位为0，则前缀范围为0~pre-1, 后缀范围为0~99..9
            if(ve[i] == 0) ans += pre*pow;
            //如果该位为1，则前缀范围为0~pre-1时, 后缀范围为0~99..9, 前缀为pre时,后缀范围为0~suf
            else if(ve[i] == 1) ans += pre*pow+suf+1;
            //否则, 前缀范围为0~pre，后缀范围为0~99..9
            else ans += (pre+1)*pow;
            pre /= 10, suf += ve[i]*pow, pow *= 10;
        }
        return ans;
    }
};
