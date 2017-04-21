class Solution {
public:
    bool judge(string& a, string& b){
        int i = 0, j = b.size()-1;
        while(i < a.size()&&j >= 0&&a[i] == b[j]) i++, j--;
        if(i < a.size()&&j >= 0) return false;
        if(j < 0){
            j = a.size()-1;
            while(i < j&&a[i] == a[j]) i++, j--;
            return i >= j;
        }
        else{
            i = 0;
            while(i < j&&b[i] == b[j]) i++, j--;
            return i >= j;
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words.size(); j++)
                if(i != j&&judge(words[i], words[j]))
                    ans.push_back({i, j});
        return ans;
    }
};
