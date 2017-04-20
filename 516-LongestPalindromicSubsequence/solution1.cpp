class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), 0));
        return longestPalindromeSubseq(s, 0, s.size()-1, memo);
    }
    int longestPalindromeSubseq(string &s, int left, int right, vector<vector<int>> &memo){
        if(left == right) return 1;
        if(left > right) return 0;
        if(memo[left][right]) return memo[left][right];
        return s[left] == s[right] ? 2 + longestPalindromeSubseq(s,left+1,right-1,memo) : memo[left][right]=max(longestPalindromeSubseq(s,left,right-1,memo),longestPalindromeSubseq(s,left+1,right,memo));
    }
};
