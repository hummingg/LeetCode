/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

// @lc code=start
class OrderedStream {
    // 87 33 96 82.9;
private:
    vector<string> vs;
    int ptr = 1;
    int n;
public:
    OrderedStream(int n) {
        this->n = n;
        vector<string> v(n+1, "");
        vs = v;
    }
    
    vector<string> insert(int idKey, string value) {
        vs[idKey] = value;
        vector<string> v;
        while(ptr <= n && vs[ptr] != ""){
            v.push_back(vs[ptr]);
            ++ptr;
        }
        return v;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

