class Solution
{
public:
    void mergeSort(vector<pair<int,int>> &nums,int L,int R,vector<int> &ans)
    {
        if(R-L<=1)    return;
        int mid=(L+R)/2;
        mergeSort(nums,L,mid,ans);
        mergeSort(nums,mid,R,ans);
        int rp=mid;
        for(int i=L;i<mid;i++)
        {
            while(rp<R&&nums[i].first>nums[rp].first)   ++rp;
            ans[nums[i].second]+=rp-mid;
        }
        inplace_merge(nums.begin()+L,nums.begin()+mid,nums.begin()+R);
    }
    vector<int> countSmaller(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)    return {};
        vector<int> ans(n,0);
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)    vec.push_back({nums[i],i});
        mergeSort(vec,0,n,ans);
        return ans;
    }
};
