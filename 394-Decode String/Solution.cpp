class Solution {
public:
    string decodeString(string s) {
        stack<int> S;//使用栈来保存每一层的重复次数
        stack<string> ST;//存储每一层的字符串
        int len = s.size();
        int times = 0;
        string tmp = "";
        for(int i=0;i<len;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                times = times*10 + (s[i]-'0');//解析重复次数
                continue;
            }
            if(s[i]=='[')
            {
                S.push(times);
                ST.push(tmp);//先将当前层的串存储起来，以准备进行拼接
                tmp = "";
                times = 0;
                continue;
            }
            if(s[i] == ']')
            {
                string t = tmp;
                int x = S.top();
                S.pop();
                for(int j=1;j<x;j++) tmp += t;
                t= tmp;
                tmp = ST.top();ST.pop();
                tmp+=t;
                continue;
            }
            tmp+=s[i];//与当前层的串进行合并
        }
        return tmp;
    }
};
