class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0, last = 0;
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].start < intervals[last].end) ++res;
            else last = i;
        }
        return res;
    }

    static bool cmp(const Interval& x, const Interval& y) {
        return x.end < y.end;
    }
};