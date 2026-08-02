#include <vector>
#include <list>
#include <utility>

using namespace std;

class MyHashMap {
private:
    static const int BUCKETS = 10007; // Prime bucket size minimizes hash collision collisions
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % BUCKETS;
    }

public:
    MyHashMap() : table(BUCKETS) {}
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto& entry : table[idx]) {
            if (entry.first == key) {
                entry.second = value; // Key exists, update value
                return;
            }
        }
        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        for (const auto& entry : table[idx]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                return;
            }
        }
    }
};
