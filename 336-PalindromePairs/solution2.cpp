  class Solution {
    public:
        bool judge(string& str){
            int i = 0, j = str.size() - 1;
            while(i < j)
                if(str[i++] != str[j--]) return false;
            return true;
        }
        vector<vector<int>> palindromePairs(vector<string>& words) {
            unordered_map<string, int> ma;
            vector<vector<int>> ans;
            for(int i = 0; i < words.size(); i++)
                ma[{words[i].rbegin(), words[i].rend()}] = i;
            if(ma.find("") != ma.end()){
                for(int i = 0, k = ma[""]; i < words.size(); i++)
                    if(words[i] != ""&&judge(words[i]))
                        ans.push_back({k, i});
            }
            for(int i = 0; i < words.size(); i++) {
                for(int j = 0; j < words[i].size(); j++) {
                    string l = words[i].substr(0, j), r = words[i].substr(j, words[i].size()-j);
                    if(ma.find(l) != ma.end()&&judge(r)&&ma[l] != i)
                        ans.push_back({i, ma[l]});
                    if(ma.find(r) != ma.end()&&judge(l)&&ma[r] != i)
                        ans.push_back({ma[r], i});
                }
            }
            return ans;
        }
    };
