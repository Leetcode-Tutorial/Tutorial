class Solution1 {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        for(int i=0; i<equations.size(); i++)
        {
            string x = equations[i].first;
            string y = equations[i].second;
            Addlink(x, y, values[i]);
            if(values[i]!=0)//判断当前比例是否非0，否则可以建立一条合法的反向边
            Addlink(y , x, 1.0/values[i]);
        }
        for(auto x:F)
            Addlink(x.first, x.first, 1.0);//每个节点建立一条自己到自己的边
        Floyd();
        for(auto i:queries)
        {
            string x = i.first;
            string y = i.second;
            if(F[x].find(y)== F[x].end()) ans.push_back(-1.0);
            else ans.push_back(F[x][y]);
        }
        return ans;
    }
    void Addlink(const string &x, const string &y, const double &va)
    {
        if(F.find(x) == F.end())
            F[x]=unordered_map<string,double>();
        F[x][y]=va;
    }
    void Floyd()//佛洛依德算法，处理出任意一个点对的路径值
    {
        for(auto k:F)//枚举中转节点
            for(auto x:F)
            {
                if(F[x.first].find(k.first)==F[x.first].end()) continue;
                for(auto y:F)
                {
                    if(F[k.first].find(y.first)==F[k.first].end()) continue;
                    F[x.first][y.first] = F[x.first][k.first]*F[k.first][y.first];
                }
            }
    }
private:
    map<string, unordered_map<string,double>> F;//存储当前图的联系情况
};
