void search(string board,string hand,int cond,int now,int& ans)//DFS搜索，参数分别为当前串，手上的珠子，手上珠子是否被使用过（状态压缩，0代表使用过，1代表未使用，当前层数，当前答案）
{
    if(now==ans)return;//当前搜索层数达到答案，不用再搜索了
    int lenb=board.size(),lenh=hand.size();
    if(lenb==0)//当前串已空
    {
        ans=now;
        return;
    }
    for(int i=0;i<lenh;i++)
    {
        if(!(cond&(1<<i)))continue;//这个珠子已被用过
        for(int j=0;j<lenb;j++)
        {
            if(board[j]==hand[i]&&(j==0||board[j]!=board[j-1]))//找到有同色珠子的位置，固定插在一串连续同色珠子的第一个前面，以免重复搜索
            {
                string nowb=board;
                nowb.insert(nowb.begin()+j,hand[i]);//生成新的串
                char nowcheck;
                int cnt=0;
                int lennow=lenb+1;
                int ok=0;
                while(!ok)//进行消去工作，ok=0说明是第一次检查或者上一次有消去还要检查是否还有连击
                {
                    int f=0;
                    ok=1;
                    while(f<lennow)
                    {
                        if(f==0||nowb[f]!=nowcheck)//当前珠子是第一个或者和前一个珠子颜色不同
                        {
                            nowcheck=nowb[f];
                            cnt=1;
                        }
                        else//当前珠子和前一个颜色相同
                        {
                            cnt++;
                            if(cnt==3)//数量达到三个，进行消去
                            {
                                while(f-2<lennow&&nowb[f-2]==nowcheck)
                                {
                                    nowb.erase(nowb.begin()+f-2);
                                    lennow--;
                                }
                                ok=0;
                                break;
                            }
                        }
                        f++;
                    }
                }
                search(nowb,hand,cond^(1<<i),now+1,ans);//搜索下一层
            }
        }
    }
}
int findMinStep(string board, string hand)
{
    int lenh=hand.size();
    int ans=-1;
    search(board,hand,(1<<lenh)-1,0,ans);//DFS搜索
    return ans;
}
