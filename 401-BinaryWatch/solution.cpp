class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int h=0; h<12; h++)
            for(int m=0; m<60; m++){
                if(bitset<10>((h<<6)+m).count() == num)
                    result.emplace_back(to_string(h) + (m<10 ? ":0":":") + to_string(m));
            }
        return result;
    }
};
