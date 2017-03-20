class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        M.clear();
        V.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(M.find(val)!=M.end()) return false;
        M[val] = V.size();
        V.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(M.find(val)==M.end()) return false;
        int no = M[val];//取出被删除的元素存储在容器V当中的位置
        V[no] = V[V.size()-1];//将容器尾端的元素填补至被删除的位置
        int x = V[no];
        M[x] = no;//维护M至V的映射关系
        V.pop_back();
        M.erase(M.find(val));
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if(V.size()) return V[rand()%V.size()];
        else return 0;
    }
private: unordered_map<int, int> M;
         vector<int> V;
};
