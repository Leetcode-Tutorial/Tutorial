class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        } else if(s.length() == 0) {
            return true;
        }
        
        stack<char>st;
        
        st.push(s[0]);
        for(int i = 1; i < s.length(); i ++) {
            if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }else if(!st.empty() && s[i] == '}') {
                if(st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }else if(!st.empty() && s[i] == ']') {
                if(st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(s[i]);
            }
        }
        if(st.size() == 0) {
            return true;
        }
        return false;
    }
};
