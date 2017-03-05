int trap(vector<int>& height)
{
    int ans=0;
    stack<int> s,id;
    int len=height.size();
    for(int i=0;i<len;i++)
    {
        int pre=0;//前一次计算的海拔，初始化为0
        while(!s.empty()&&height[i]>=s.top())//栈不空且当前海拔不小于栈顶海拔
        {
            ans=ans+(i-id.top()-1)*(s.top()-pre);//更新答案
            pre=s.top();//更新上一次计算的海拔
            s.pop();
            id.pop();//栈顶元素弹出
        }
        if(!s.empty())//退出后如果栈不空还需要再计算一次
        {
            ans=ans+(i-id.top()-1)*(height[i]-pre);
            pre=s.top();
        }
        s.push(height[i]);
        id.push(i);//压栈
    }
    return ans;
}
