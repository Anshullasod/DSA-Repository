class RandomizedSet {
public:
    RandomizedSet() {
       
    }
     unordered_map<int, int> m;
     vector<int> vec;

    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }
        vec.push_back(val);
        m[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        vec[m[val]] = vec[vec.size() - 1];
        m[vec[vec.size() - 1]] = m[val];
        vec.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() { return vec[rand() % vec.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */