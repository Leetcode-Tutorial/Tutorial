class Solution {
public:
     int findMinArrowShots(vector<pair<int, int>>& points) {
        int cnt = 0, now = -0x3f3f3f3f;
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < (int)points.size(); i++){
            if (now != -0x3f3f3f3f && points[i].first <= now) continue; 
            now = points[i].second; 
            cnt++;
        }
        return cnt;
    }

    static bool cmp(pair<int, int>& x, pair<int, int>& y){
        return x.second == y.second ? x.first > y.first : x.second < y.second;
    }
};