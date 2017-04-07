#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mergeSort(vector<long long> &sum,int L,int R,int lower,int upper)
    {
        if(L==R)    return 0;
        int mid=(L+R)/2;
        int count=mergeSort(sum,L,mid,lower,upper)+mergeSort(sum,mid+1,R,lower,upper);
        int lp=mid+1,rp=mid+1;
        for(int i=L;i<=mid;i++)
        {
            while(lp<=R&&sum[lp]-sum[i]<lower)    ++lp;
            while(rp<=R&&sum[rp]-sum[i]<=upper)   ++rp;
            count+=rp-lp;
        }
        inplace_merge(sum.begin()+L,sum.begin()+mid,sum.begin()+R+1);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        int n=nums.size()+1;
        vector<long long> sum(n,0);
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+nums[i-1];
        return mergeSort(sum,0,n,lower,upper);
    }
};
