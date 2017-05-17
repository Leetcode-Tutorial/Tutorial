class Solution {
    public:
        static bool cmp(const Interval &a, const Interval &b) {
            return a.start < b.start;
        }

        vector<Interval> merge(vector<Interval>& ins) {
            vector <Interval> res;
            if (ins.empty()) return res;
            sort(ins.begin(), ins.end(), cmp);
            res.push_back(ins[0]);
            int cnt = ins.size();
            for (int i = 1; i < cnt; i++) {
                if (ins[i].start <= res.back().end) {
                    res.back().end = max(res.back().end, ins[i].end);
                }
                else {
                    res.push_back(ins[i]);
                }
            }
            return res;
        }
};