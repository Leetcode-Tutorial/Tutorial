class Solution
{
public:
    int maxPoints(vector<Point>& points)
    {
        int n=points.size(),ans=0;
        if(n==0)    return 0;
        for(int i=0;i<points.size();i++)
        {
            map<pair<int,int>,int> mp;
            int same=0,mx=0;
            for(int j=0;j<points.size();j++)
            {
                int x=points[j].x-points[i].x;
                int y=points[j].y-points[i].y;
                if(x==0&&y==0)
                {
                    ++same;
                    continue;
                }
                int gcd=__gcd(x,y);
                if(gcd)    x/=gcd,y/=gcd;
                ++mp[{x,y}];
                mx=max(mx,mp[{x,y}]);
            }
            ans=max(ans,mx+same);
        }
        return ans;
    }
};
