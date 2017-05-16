class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = false;
        int count_upper = 0;
        for(int i = 0;i<word.length();i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
            {
                count_upper++;
            }
        }
        if(count_upper == word.length() || count_upper == 0|| (count_upper == 1 && (word[0] >= 'A'&&word[0] <= 'Z')))
            flag = true;
        return flag;
    }
};