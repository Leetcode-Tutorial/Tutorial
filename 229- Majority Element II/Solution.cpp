class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans(0, 0);
        if(!nums.size()) return ans;
        int num_a = nums[0] , num_b = 0 , cnt_a=1 , cnt_b= 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == num_a)
            {
                cnt_a++;
            }
            else if(nums[i] == num_b)
            {
                cnt_b ++ ;
            }
            else if(cnt_a == 0)
            {
                num_a = nums[i];
                cnt_a = 1;
            }
            else if(cnt_b == 0)
            {
                num_b = nums[i];
                cnt_b = 1;
            }
            else
            {
                cnt_a--;
                cnt_b--;
            }
        }
        //check
        cnt_a = cnt_b = 0;
        for(auto x:nums)
        {
            if(x == num_a) cnt_a++;
            if(x == num_b) cnt_b++;
        }
        if(cnt_a > nums.size()/3) ans.push_back(num_a);//检查num_a是否合法
        if(cnt_b > nums.size()/3 && num_a != num_b) ans.push_back(num_b);//检查num_b是否合法
        return ans;
    }
};
