class Solution {
public:
    string intToRoman(int num) {
        char romanChar[] = {'I','V','X','L','C','D','M'};
        string res;
        int i = 6, factor = 1000;
        while(num != 0)
        {
            helper(num / factor, &romanChar[i], res);
            i -= 2;
            num %= factor;
            factor /= 10;
        }
        return res;
    }
     
    void helper(int k, char romanChar[], string &res)
    {// 0 <= k <= 9
        if(k <= 0);
        else if(k <= 3)
            res.append(k, romanChar[0]);
        else if(k == 4)
        {
            res.push_back(romanChar[0]);
            res.push_back(romanChar[1]);
        }
        else if(k <= 8)
        {
            res.push_back(romanChar[1]);
            res.append(k-5, romanChar[0]);
        }
        else if(k == 9)
        {
            res.push_back(romanChar[0]);
            res.push_back(romanChar[2]);
        }
    }
};
