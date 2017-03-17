vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> res;
    int len=words.size();//字符串个数
    int f=0,nowwid,last=0;
    while(f<len)
    {
        nowwid=0;//当前已取字符个数
        while(f<len&&nowwid<=maxWidth)//未取到最后一个并且字符个数未超过给定长度
        {
            nowwid=nowwid+words[f].size();
            if(f>last)nowwid++;//不是第一个字符串要额外加1
            f++;
        }
        if(nowwid>maxWidth)f--;//字符个数超过给定长度
        nowwid=0;
        for(int i=last;i<f;i++)//统计非空格字符数
        {
            nowwid=nowwid+words[i].size();
        }
        //cout<<"last:"<<last<<" f:"<<f<<endl;
        int spacecnt,addnum;
        if(f-last==1)//只有一个字符串
        {
            spacecnt=maxWidth-nowwid;
            addnum=0;
        }
        else
        {
            spacecnt=(maxWidth-nowwid)/(f-last-1);//两个字符串间空格数
            addnum=(maxWidth-nowwid)%(f-last-1);//有多少个空隙要额外补字符
        }
        string ans;
        for(int i=last;i<f;i++)//构造该行答案
        {
            ans=ans+words[i];
            if(f<len)//不是最后一行
            {
                if(i<f-1||last==f-1)
                {
                    for(int j=1;j<=spacecnt;j++)//加空格
                    {
                        ans=ans+" ";
                    }
                    if(i-last<addnum)ans=ans+" ";//额外补空格
                }
            }
            else//是最后一行
            {
                if(i<f-1)ans=ans+" ";//前面的空隙只要一个空格
                else
                {
                    for(int j=1;j<=maxWidth-(nowwid+(f-last-1));j++)//最后一个字符串后补空格
                    {
                        ans=ans+" ";
                    }
                }
            }
        }
        res.push_back(ans);
        //cout<<ans<<endl;
        last=f;//更新上一次取的下一个字符串的位置
    }
    return res;
}
