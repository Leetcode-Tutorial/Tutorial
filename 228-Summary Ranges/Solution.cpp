class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans(0,"");
        if(nums.size() == 0) return ans;
        int L,R;
        to_array
        L = R = nums[0];//初始化左右指针
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == R+1)//尝试将右指针进行拓展
            {
                R = nums[i];
            }
            else
            {
                ans.push_back(generate_str(L,R));//无法拓展则合并区间，并移动指针
                L = R = nums[i];
            }
        }
        ans.push_back(generate_str(L,R));
        return ans;
    }
    string generate_str(const int &L, const int &R)
    {
        if(L == R)
            return to_string(L);
        else return to_string(L) + "->" + to_string(R);
    }
};
