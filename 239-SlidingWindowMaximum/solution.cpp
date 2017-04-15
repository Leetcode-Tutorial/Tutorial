class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        deque<int> que;
        for(int i=0;i<nums.size();i++)
        {
            while(!que.empty()&&nums[i]>nums[que.back()])
                que.pop_back();
            que.push_back(i);
            if(i-que.front()+1>k)   que.pop_front();
            if(i+1>=k)    ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};
