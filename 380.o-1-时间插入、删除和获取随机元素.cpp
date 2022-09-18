/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
    // WA
private:
    // 随机访问
    map<int, int> flag;
    // map<int, int> vals;
    // vector<int> eles;
    // vector<int> idx;
    int size = 0;
public:
    // Wrong
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(flag.find(val) != flag.end()){
            return false;
        }
        flag[val] = size;
        // eles.push_back(val);
        ++size;
        return true;
    }
    
    bool remove(int val) {
        if(flag.find(val) == flag.end()){
            return false;
        }
        // eles.erase(eles.begin() + flag[val]);
        flag.erase(val);
        // --size;
        return true;
    }
    
    int getRandom() {
        default_random_engine e;
        e.seed(time(0));
        int idx = e() % flag.size();
        // cout << (flag.begin() + 1)->first << endl;
        // return idx;
        // return (flag.begin() + e() % flag.size())->first;
        
        // return (flag.begin()+idx)->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

