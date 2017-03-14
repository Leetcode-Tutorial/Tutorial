class Solution {
public:
    long long ans, num;
    const long long INF = 0x3f3f3f3f3f3f3f3fLL;

    long long myPow(long long a, long long y) {
    	long long res = 1;
    	while (y) {
    		if (y & 1) res = res * a;
    		a = a * a;
    		y >>= 1;
    	}
    	return res;
    }
    
    long long cal(long long x, int y) {
    	if (log(num) / log(x) < y - 1) return INF;
    	long long res = 0;
    	for (int i = 0; i < y; i++) 
    		res += myPow(x, i);
    	return res;
    }
    
    void binSerch(long long l, long long r, int y) {
    	while (l <= r) {
    		long long m = (l + r) >> 1LL, tmp = cal(m, y);
    		if (tmp == num) {
    			ans = min(ans, m);
    			return;
    		}
    		else if (tmp > num) r = m - 1;
    		else l = m + 1;
    	}
    }
    
    string smallestGoodBase(string n) {
        for (int i = 0; i < n.length(); i++)
    		num = num * 10 + n[i] - '0'; 
    	ans = INF;
    	for (int i = 1; i < 64; i++) {
    		binSerch(2, num - 1, i);
    	}
    	string res = "";
    	while (ans) {
    		res += ans % 10 + '0';
    		ans /= 10;
    	}
    	reverse(res.begin(), res.end());
        return res;
    }
};