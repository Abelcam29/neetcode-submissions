class MyHashSet {
private:
    int size;
    vector<list<int>> table;

    int hash(int key)
    {
        return key % size;
    }
public:
    MyHashSet() {
        size = 10007;
        table.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        if(!contains(key))
        {
            table[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        auto it = find(bucket.begin(), bucket.end(), key);
        if(it != bucket.end())
        {
            bucket.erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        auto it = find(bucket.begin(), bucket.end(), key);
        return it != bucket.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */