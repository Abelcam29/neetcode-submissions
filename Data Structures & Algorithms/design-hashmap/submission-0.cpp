class MyHashMap {
private:
    int size;
    vector<list<pair<int,int>>> table;
    int hash(int key)
    {
        return key % size;
    }
public:
    MyHashMap() {
        size = 10007;
        table.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        auto& bucket = table[idx];

        for(auto& entry : bucket)
        {
            if(entry.first == key)
            {
                entry.second = value;
                return;
            }
        }
        bucket.push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        for(auto& entry : bucket)
        {
            if(entry.first == key)
            {
                return entry.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        for(auto it = bucket.begin(); it != bucket.end(); it++)
        {
            if(it->first == key)
            {
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */