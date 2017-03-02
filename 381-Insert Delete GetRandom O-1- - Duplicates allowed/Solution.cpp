class RandomizedCollection {
public:
    RandomizedCollection() {
        //初始化两个容器
        M.clear();
        V.clear();
    }

    bool insert(int val) {
        bool st = (M.find(val) == M.end());

        M[val].push_back(V.size());
        V.push_back( make_pair(val, M[val].size()-1));
        return st;
    }

    bool remove(int val) {
        bool st = (M.find(val) != M.end());
        if(!st) return st;
        int x = M[val].back();
        auto last = V.back();
        M[last.first][last.second] = x;
        V[x] = last;
        M[val].pop_back();
        if(M[val].empty()) M.erase(val);//如果所有值为val的元素都已经被移除，则在map中删除
        V.pop_back();
        return st;
    }

    int getRandom() {
        return V[rand()%V.size()].first;
    }
private:
    unordered_map<int, vector<int>> M;//存储的是值为x的值在V中各个存储的单元的位置
    vector<pair<int, int>> V;//容器中，第一个元素表示当前存储的值;\
    第二个元素表示的意思是其在对应的map的映射的vector中存储单元的序号
};
