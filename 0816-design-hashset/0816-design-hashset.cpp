class MyHashSet {
private:
    unordered_set<int>s;
public:
    MyHashSet() {
       // nothing to initialize
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        return s.find(key) != s.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */