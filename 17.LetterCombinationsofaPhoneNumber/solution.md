class Solution {
public:
    void work(string digits, string &temp, vector<string>& result, vector<string>dict) {
        
        int len = temp.length(), lend = digits.length();
        if(len == lend) {
            result.push_back(temp);
            return ;
        }
        
        for(int i = 0; i < dict[digits[len] - '0'].length(); i ++) {
            temp += dict[digits[len] - '0'][i];
            work(digits, temp, result, dict);
            temp.erase(temp.length() - 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {

        vector<string>dict(10);
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        
        vector<string>result;
        
        if(digits.length() == 0) {
            return result;
        }
        string temp = "";
        work(digits, temp, result, dict);
        return result;
    }
};
