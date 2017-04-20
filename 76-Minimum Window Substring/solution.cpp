string minWindow(string s, string t)
{
    int cnt_in_t[260]={0},cnt_in_window[260]={0},existcnt_in_s=0;
    int ansl=-1,ansr=-1;
    int lens=s.size(),lent=t.size();
    for(int i=0;i<lent;i++)
    {
        cnt_in_t[t[i]]++;//统计t串中每个字符出现数目
    }
    for(int i=0;i<260;i++)
    {
        if(cnt_in_t[i]==cnt_in_window[i])existcnt_in_s++;//先统计空串情况下有多少字符满足要求
    }
    int left=0,right=0;
    while(right<lens)
    {
        while(right<lens&&existcnt_in_s<260)//右指针向右滑
        {
            int now=s[right];
            right++;
            cnt_in_window[now]++;
            if(cnt_in_window[now]==cnt_in_t[now])existcnt_in_s++;//当前字符个数符合要求
        }
        if(existcnt_in_s<260)break;//右指针滑完了s但当前区间不符合要求
        while(left<right&&existcnt_in_s==260)//左指针向右滑
        {
            int now=s[left];
            left++;
            cnt_in_window[now]--;
            if(cnt_in_window[now]==cnt_in_t[now]-1)existcnt_in_s--;//当前字符个数不符合要求
        }
        if(ansl==-1||right-left<ansr-ansl)//更新答案区间
        {
            ansl=left-1;
            ansr=right-1;
        }
    }
    string ans="";//得到最终答案
    for(int i=ansl;i<=ansr;i++)
    {
        ans=ans+s[i];
    }
    return ans;
}
