class Solution {
public:
    
    void work(int n, string dict, int& left, int& right, string& temp, vector<string>& result) {
        if(left == n && right == n) {
            result.push_back(temp);
            return ;
        }
        
        if(left < n) {
            temp += "(";
            left += 1;
            work(n, dict, left, right, temp, result);
            temp.erase(temp.length() - 1);
            left -= 1;
        }
        if(left > right) {
            temp += ")";
            right += 1;
            work(n, dict, left, right, temp, result);
            temp.erase(temp.length() - 1);
            right -= 1;
        }
    }

    vector<string> generateParenthesis(int n) {
        
        string dict = "()";
        int left = 0, right = 0; // record the num of left parentheses and right parentheses
        
        vector<string> result;
        if(n == 0) {
            return result;
        }
        
        string temp = "(";
        left = 1;
        work(n, dict, left, right, temp, result);
        return result;
    }
};
