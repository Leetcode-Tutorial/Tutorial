/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> left, right;
        int start=newInterval.start;
        int end=newInterval.end;
        for(const auto& interval: intervals){
            if(start>interval.end) left.emplace_back(interval);
            else if(end<interval.start) right.emplace_back(interval);
            else{
                //merge intervals
                start=min(start, interval.start);
                end=max(end, interval.end);
            }
        }
        //result: left + newInterval + right
        left.emplace_back(Interval(start, end));
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
