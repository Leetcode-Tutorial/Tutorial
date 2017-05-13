class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        auto it1 = s.begin(), it2 = s.end()-1;
        while(it1 < it2){
            while(it1 < it2 && !(isdigit(*it1)||isalpha(*it1)) ) it1++;
            while(it1 < it2 && !(isdigit(*it2)||isalpha(*it2)) ) it2--;
            if(islower(*it1)) *it1 = toupper(*it1);
            if(islower(*it2)) *it2 = toupper(*it2);
            if(*it1++ != *it2--) return false;
        }
        return true;
    }
};
