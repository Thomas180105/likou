class RandomizedSet {
//要O(1)插入，删除，所以要上哈希表
//要O(1)随机访问，所以要上顺序数据结构，数组
//考虑vector+unordered_map
private:
    unordered_map<int, int> hash;//从val->vec中index
    vector<int> vec;//存val
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (hash.count(val)) return false;
        hash[val] = vec.size();
        vec.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (!hash.count(val)) return false;

        // 2->0 3->1 5->2
        // 2 3 5
        //删除2
        //2->0 3->1 5->2 => 3->1 5->2 => 3->1 5->0
        //2 3 5-> 5 3 5 => 5 3 
        // vec[hash[vec.back()]] = hash[val];
        // vec.pop_back();
        hash[vec.back()] = hash[val];
        vec[hash[val]] = vec.back();
        hash.erase(val);
        vec.pop_back();
        return true;
    }

    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */