bool checkRecord(string s)
{
    int len=s.size();
    int cntA=0,cntL=0;
    for(int i=0;i<len;i++)
    {
        switch(s[i])
        {
            case 'A':
                cntL=0;
                cntA++;
                if(cntA>1)return false;//缺勤次数超过1次
                break;
            case 'L':
                cntL++;
                if(cntL>2)return false;//连续迟到次数超过2次
                break;
            case 'P':
                cntL=0;
                break;
        }
    }
    return true;
}
