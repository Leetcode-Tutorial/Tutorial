class Solution {
public:
    #define maxn 100005 
    int len[maxn<<1];  
	char a[maxn];  

    string longestPalindrome(string s) { 
	    char ss[maxn<<1];//构造新串  
	    int n = s.length (), l = 0;  
	    ss[l++] = '@';  
	    ss[l++] = '#';  
	    for (int i = 0; i < n; i++) {  
	        ss[l++] = s[i];  
	        ss[l++] = '#';  
	    }  
	    ss[l++] = '~'; ss[l] = 0;    
	  
	    int Max = 0, pos = 0, ans = 0;  
	    for (int i = 1; i < l; i++) {  
	        if (Max > i) {  
	            len[i] = min (len[2*pos-i], Max-i);  
	        }  
	        else  
	            len[i] = 1;  
	        while (ss[i+len[i]] == ss[i-len[i]])  
	            len[i]++;  
	        ans = max (ans, len[i]);  
	        if (len[i]+i > Max) {  
	            Max = len[i]+i;  
	            pos = i;  
	        }  
	    }  
	    string cur = "";
	    for (int i = 0; i < l; i++) if (len[i] == ans) {
	    	for (int j = i-len[i]+1; j < i+len[i]-1; j++) {
	    		if (ss[j] != '#') cur += ss[j];
	    	}
	    	break;
	    }
	    return cur;
    }

};
