class Solution
{
public:
    int strongPasswordChecker(string s)
    {
        int n=s.size(),low=0,upp=0,dig=0;

        typedef pair<int,int> pii;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a'&&s[i]<='z')    low=1;
            if(s[i]>='A'&&s[i]<='Z')    upp=1;
            if(s[i]>='0'&&s[i]<='9')    dig=1;
            int cnt=1;
            while(i+1<n&&s[i+1]==s[i])    ++i,++cnt;
            if(cnt>=3)
                pq.push({cnt%3,cnt});
        }
        int type=low+upp+dig;

        if(n<6)
        {
            int mc=0;
            while(!pq.empty())
            {
                mc=max(mc,pq.top().second);
                pq.pop();
            }
            if(mc==5)
                return 2;
            return max(6-n,3-type);
        }

        int del=max(n-20,0);
        while(!pq.empty()&&n>20)  // 优先删除连续的
        {
            pii v=pq.top();pq.pop();
            int mod=v.first,r=v.second;
            int m=min(mod+1,n-20);
            n-=m;
            if(r-m>=3)    pq.push({2,r-m});
        }

        int change=0;
        while(!pq.empty())   // 删除后仍剩下的连续的
        {
            change+=pq.top().second/3;
            pq.pop();
        }

        return del+max(change,3-type);
    }
};
