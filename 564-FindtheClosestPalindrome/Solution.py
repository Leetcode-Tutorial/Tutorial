class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        l = len(n)
        if l == 1: return str(int(n)-1)

        #n = 99...99
        if len(set(n)) == 1 and n[0] == '9':
            return '1'+'0'*(l-1)+'1'

        #n = 10...00, 10...01
        if n[0] == '1' and int(n[-1]) <= 1 and (l == 2 or set(n[1:-1]) == set('0')):
            return '9'*(l-1)

        #n >= 12
        m, s = (l-1)//2, list(n)
        s = s[:m+1]+(s[m::-1] if l%2 == 0 else s[m-1::-1])
        x= ''.join(s)
 
        if int(x) == int(n):
            if s[m] != '0':
                s[m] = s[l-1-m] = str(int(s[m])-1)
                return ''.join(s)
            #s[m] == '0'
            s[m] = s[l-1-m] = '1'
            x = ''.join(s)#x > 
            s[m] = s[l-1-m] = '0'
            while s[m] == '0':
                s[m] = s[l-1-m] = '9'
                m -= 1
            s[m] = s[l-1-m] = str(int(s[m])-1)
            y = ''.join(s)#y <
        elif int(x) < int(n):
            while s[m] == '9':
                s[m] = s[l-1-m] = '0'
                m -= 1
            s[m] = s[l-1-m] = str(int(s[m])+1)
            y = ''.join(s)
        else:
            while s[m] == '0':
                s[m] = s[l-1-m] = '9'
                m -= 1
            s[m] = s[l-1-m] = str(int(s[m])-1)
            y = ''.join(s)
        
        if abs(int(x)-int(n)) == abs(int(y)-int(n)):
            return str(min(int(x), int(y)))
        return x if abs(int(x)-int(n)) < abs(int(y)-int(n)) else y
