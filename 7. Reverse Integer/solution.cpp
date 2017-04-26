class Solution {
public:
    int reverse(int x) {
       long long  int s = 0;              //它有可能会超过int的值
        while(x!=0)
        {
            s = s*10+x%10;                //进行反转
            x/=10;
        }
        if(s>INT_MAX || s<INT_MIN)
            return 0;
        else
            return s;
    }
};