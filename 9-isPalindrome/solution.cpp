class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        vector <int> number; number.clear ();
        while (x) {
            number.push_back (x%10);
            x /= 10;
        }
        int n = number.size ();
        for (int i = 0; i < n/2; i++) {
            if (number[i] != number[n-i-1]) return 0;
        }
        return 1;
    }
};
