    class Solution {
    public:

        struct Node
        {
            unordered_set<int> neighbor;
            bool isLeaf()const{return neighbor.size()==1;}//判断一个节点是否为当前的叶子结点
        };

        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

            vector<int> buffer1;
            vector<int> buffer2;
            vector<int>* pB1 = &buffer1;
            vector<int>* pB2 = &buffer2;
            if(n==1)
            {
                buffer1.push_back(0);
                return buffer1;
            }
            if(n==2)
            {
                buffer1.push_back(0);
                buffer1.push_back(1);
                return buffer1;
            }
            vector<Node> nodes(n);//建树
            for(auto p:edges)
            {
                nodes[p.first].neighbor.insert(p.second);
                nodes[p.second].neighbor.insert(p.first);
            }

            for(int i=0; i<n; ++i)
            {
                if(nodes[i].isLeaf()) pB1->push_back(i);//寻找度为1的叶子节点
            }

            while(1)
            {
                for(int i : *pB1)
                {
                    for(auto n: nodes[i].neighbor)
                    {
                        nodes[n].neighbor.erase(i);//更新所连接的点的度
                        if(nodes[n].isLeaf()) pB2->push_back(n);//如果当前点为叶子节点，则压入容器
                    }
                }
                if(pB2->empty())
                {
                    return *pB1;//无可删除节点时，便得到所需要的答案
                }
                pB1->clear();
                swap(pB1, pB2);
            }

        }
    };
