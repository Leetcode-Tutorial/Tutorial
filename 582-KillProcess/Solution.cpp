class Solution {
public:
    int findf(int x, unordered_map<int, int>& dict, int kill){
        int f = dict[x];
        if(f == 0||f == kill) return f;
        return dict[x] = findf(f, dict, kill);
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, int> dict;
        for(int i = 0; i < pid.size(); i++)
            dict[ pid[i] ] = ppid[i];
        vector<int> ans = {kill};
        for(int i: pid){
            findf(i, dict, kill);
            if(dict[i] == kill) ans.push_back(i);
        }
        return ans;
    }
};
