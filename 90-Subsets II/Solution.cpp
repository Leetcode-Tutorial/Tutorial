class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> V;
        map<int, int> M;
        for(auto i:nums)//初始化，记录每个整数i出现在nums集合内的次数
            M[i] = M[i]+1;

        for(auto i=M.begin(); i!=M.end() ;i++)
        {
            int cnt = M[i->first];
            int l = V.size();
            for(int k=0;k<l;k++)//若当前整数x第一次出现,将当前集合V的每个元素都与x组合
            {
                vector<int> tmp = V[k];
                tmp.push_back(i->first);
                V.push_back(tmp);
            }
            V.push_back(vector<int>(1,i->first));
            int r = V.size();//通过l与r标识元素x出现n次的子集在vector内存储的区间
            for(int j=1;j<cnt;j++)
            {
                for(int k=l;k<r;k++)
                {
                    vector<int> tmp = V[k];
                    tmp.push_back(i->first);
                    V.push_back(tmp);
                }
                l = r;
                r = V.size();//维护这一段左右区间
            }
        }
        V.push_back(vector<int>(0,0));//补充上一个空集
        return V;
    }
};
