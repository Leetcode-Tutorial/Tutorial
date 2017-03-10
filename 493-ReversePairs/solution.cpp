class Solution {
public:
    void add(int x, vector<int> &c){
        while(x < c.size()) c[x]++, x += x&-x;
    }
    int sum(int x, vector<int> &c){
        int ans = 0;
        while(x) ans += c[x], x -= x&-x;
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        //different sign, nums[j] < 0
        for(int i = 0, temp = 0; i < nums.size(); i++){
            if(nums[i] < 0) ans += temp;
            else temp++;
        }
        //nums[j] = 0
        for(int i = 0, temp = 0; i < nums.size(); i++){
            if(nums[i] == 0) ans += temp;
            if(nums[i] > 0) temp++;
        }
        //both > 0
        vector<int> c = vector<int>(nums.size()+1, 0);
        vector<pair<int, int>> ret;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0) ret.push_back({nums[i], i+1});
        sort(ret.begin(), ret.end());
        for(int i = ret.size()-1, j = i; i >= 0; i--){
            int x = ret[i].first, pos = ret[i].second;//nums[j]
            while(j >= 0&&ret[j].first > 2LL*x) add(ret[j].second, c), j--;
            ans += sum(pos-1, c);
        }
        //both < 0
        ret.clear();
        c = vector<int>(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < 0) ret.push_back({-nums[i], i+1});
        sort(ret.begin(), ret.end());
        for(int i = 0, j = i; i < ret.size(); i++){
            int x = ret[i].first, pos = ret[i].second;//nums[j]
            while(j < ret.size()&&ret[j].first < 2LL*x) add(ret[j].second, c), j++;
            ans += sum(pos-1, c);
        }
        return ans;
    }
};
