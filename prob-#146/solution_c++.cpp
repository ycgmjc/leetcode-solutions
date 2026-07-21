class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> storage;
    list<int> age; 
    int max_cap = 1;

public:
    LRUCache(int capacity) {
        storage.clear();
        age.clear();
        max_cap = capacity;
    }
    
    int get(int key) {
        auto it = storage.find(key);
        if (it != storage.end()) {
            age.splice(age.begin(), age, it->second.second);
            return it->second.first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = storage.find(key);

        if (it != storage.end()) {
            it->second.first = value;
            age.splice(age.begin(), age, it->second.second);
            return;
        }

        if (storage.size() == max_cap) {
            int lru_key = age.back();
            age.pop_back();
            storage.erase(lru_key);
        }

        age.push_front(key);
        storage[key] = {value, age.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 