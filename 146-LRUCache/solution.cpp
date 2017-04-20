#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity):size(capacity) {

    }

    int get(int key) {
        auto it = ma.find(key);
        if(it == ma.end()) return -1;
        int val = it->second->second;
        put(key, val);
        return val;
    }

    void put(int key, int value) {
        auto it = ma.find(key);
        if(it == ma.end()){
            if(size == ma.size()){
                int k = List.back().first;
                ma.erase(k);
                List.pop_back();
            }
        }
        else
            List.erase(it->second);
        List.push_front({key, value});
        ma[key] = List.begin();
    }
private:
    list<pair<int, int>> List;
    unordered_map<int, list<pair<int, int>>::iterator> ma;//key, iterator in list
    int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
