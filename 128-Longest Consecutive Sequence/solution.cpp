int longestConsecutive(vector<int>& nums)
{
    int ans=0;
    int len=nums.size();
    unordered_map<int,bool> used;//hash表
    for(int i=0;i<len;i++)
    {
        used[nums[i]]=false;//插入hash表，是否扫描的状态记为false
    }
    for(int i=0;i<len;i++)
    {
        if(used[nums[i]])continue;//已经扫描过，跳过
        used[nums[i]]=true;//是否扫描的状态更新为true
        int left=nums[i]-1,right=nums[i]+1;
        while(used.find(left)!=used.end())//向左扫描
        {
            used[left]=true;
            left--;
        }
        while(used.find(right)!=used.end())//向右扫描
        {
            used[right]=true;
            right++;
        }
        ans=max(ans,right-left-1);//更新答案
    }
    return ans;
}
