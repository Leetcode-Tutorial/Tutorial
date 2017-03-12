bool isNumber(string s)
{
    int switchcond[9][6]=
    {
        {-1,0,2,1,3,-1},
        {-1,-1,2,-1,3,-1},
        {-1,8,2,-1,4,5},
        {-1,-1,4,-1,-1,-1},
        {-1,8,4,-1,-1,5},
        {-1,-1,7,6,-1,-1},
        {-1,-1,7,-1,-1,-1},
        {-1,8,7,-1,-1,-1},
        {-1,8,-1,-1,-1,-1}
    };//当前状态接收不合法字符、空格、数字、正负号、小数点、指数符号所转移到的状态矩阵，-1为不合法状态
    int len=s.size();
    int nowcond=0,next;
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')next=1;
        else if(s[i]>='0'&&s[i]<='9')next=2;
        else if(s[i]=='+'||s[i]=='-')next=3;
        else if(s[i]=='.')next=4;
        else if(s[i]=='e')next=5;
        else next=0;//将所接收到的字符进行
        nowcond=switchcond[nowcond][next];//转移状态
        if(nowcond==-1)return false;//到达不合法状态
    }
    if(nowcond==2||nowcond==4||nowcond==7||nowcond==8)return true;//字符串读完到达终止状态
    else return false;
}
