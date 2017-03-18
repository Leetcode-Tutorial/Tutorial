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
            for(int k=0;k<l;k++)//特殊处理整数x第一次出现出现的情况,将当前集合V的每个元素都与x组合
            {
                vector<int> tmp = V[k];
                tmp.push_back(i->first);
                V.push_back(tmp);
            }
            V.push_back(vector<int>(1,i->first));//加入单独一个整数x构成的子集
            int r = V.size();//通过l与r标识元素x出现(j-1)次的子集在vector内存储的区间
            for(int j=2;j<=cnt;j++)//当前整数x第2次到第cnt次出现时，将 V 中 l 与 r 指出的集合区间的每个元素都与 x 组合
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
