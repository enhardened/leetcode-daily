// Problem: https://leetcode.com/explore/item/3663
class MyHashMap {
public:
    vector<vector<int>> table;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        table.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key / 1000;
        if (table[hash].empty())
            table[hash].resize(1000, -1);
        table[hash][key % 1000] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return (table[key / 1000].empty())
            ? -1
            : table[key / 1000][key % 1000];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (!table[key / 1000].empty())
            table[key / 1000][key % 1000] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 