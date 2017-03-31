class Solution {
public:
    static vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> se1, se2(nums.begin(), nums.begin()+k);
        int sz1 = k/2, sz2 = k-k/2;
        for(int i = 0; i < sz1; i++){//move the k/2 smallest nums to se1
            auto tmp = se2.begin();
            se1.insert(*tmp);
            se2.erase(tmp);
        }
        bool tag = k&1;//judge whether k is odd or even
        vector<double> ans = {tag? *se2.begin(): (*se1.rbegin()+(double)*se2.begin())/2};
        for(int i = k; i < nums.size(); i++){
            //erase nums[i-k]
            if(se1.empty()||nums[i-k] >= *se2.begin()) se2.erase( se2.find(nums[i-k]) );
            else se1.erase( se1.find(nums[i-k]) );
            //insert nums[i]
            if(!se2.empty()&&nums[i] >= *se2.begin()) se2.insert(nums[i]);
            else se1.insert(nums[i]);
            //maintain the size of se1 and se2
            if(se1.size() > sz1){
                auto tmp = --se1.end();
                se2.insert(*tmp);
                se1.erase(tmp);
            }
            else if(se1.size() < sz1){
                auto tmp = se2.begin();
                se1.insert(*tmp);
                se2.erase(tmp);
            }
            //if k is odd, push *se2.begin(), otherwise push (*se1.rbgin()+se2.bgein())/2
            ans.push_back(tag? *se2.begin(): (*se1.rbegin()+(double)*se2.begin())/2);
        }
        return ans;
    }
};
