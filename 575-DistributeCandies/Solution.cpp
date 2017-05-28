class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> se;
        for(auto x: candies)
            se.insert(x);
        return min(se.size(), candies.size()/2);
    }
};