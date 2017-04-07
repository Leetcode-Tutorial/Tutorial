class Solution {
public:

    string simplifyPath(string path) {
        
        if(path.length() == 0) {  // "" returns "", not "/" 
            return "";
        }
        
        stack<string> st;
        
        // simplify
        for(int i = 0; i < path.length(); i ++) {
            if(path[i] == '/') {
                continue;
            } else {
                string tmp;
                while(i < path.length() && path[i] != '/') {
                    tmp += path[i];
                    i ++;
                }
                if(tmp == ".") {
                    continue;
                } else if(tmp == "..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(tmp);
                }
            }
        } 
        
        // resume the string
        string ans = "/";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        } 
        if(ans.length() > 1) {
            ans[ans.length() - 1] = '\0';
        }
        return ans;
    }
};
