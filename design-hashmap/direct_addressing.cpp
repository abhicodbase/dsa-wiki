#include <vector>

using namespace std;

class MyHashMap {
private:
    vector<int> hashMap;

public:
    // Direct addressing array allocation for key range [0, 1000000]
    MyHashMap() : hashMap(1000001, -1) {}
    
    void put(int key, int value) {
        hashMap[key] = value; 
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};
