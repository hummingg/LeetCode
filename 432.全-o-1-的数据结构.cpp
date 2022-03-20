/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}

// @lc code=start

// template <class T> std::ostream& operator<< (std::ostream& out, const std::set<T>& v) {
//     if (!v.empty()) {
//         out << '[';
//         std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
//         out << "]";
//     }
//     return out;
// }

// Time Limit Exceeded 15/17 cases passed (N/A)
class AllOne {
private:
    map<string, int> mCount;    // 字符串计数
    map<int, set<string>> mSearch;   // 计数和对应字符串
    // set<int> counts; // 计数升序，最少在前，最多在后.无此项导致超时
public:
    AllOne() {
    }
    
    void inc(string key) {
        auto it = mCount.find(key);
        if(it == mCount.end()){
            mCount.insert(make_pair(key, 1));
            mSearch[1].insert(key);
            // counts.insert(1);
        }else{
            mSearch[mCount[key]].erase(key);
            if(mSearch[mCount[key]].size() == 0){
                // counts.erase(mCount[key]);
                mSearch.erase(mCount[key]);
            }
            mCount[key] += 1;
            // counts.insert(mCount[key]);
            mSearch[mCount[key]].insert(key);
        }
    }
    
    void dec(string key) {
        mSearch[mCount[key]].erase(key);
        if(mSearch[mCount[key]].size() == 0){
            // counts.erase(mCount[key]);
            mSearch.erase(mCount[key]);
        }
        mCount[key] -= 1;
        if(mCount[key] > 0){
            // counts.insert(mCount[key]);
            mSearch[mCount[key]].insert(key);
        }
    }
    
    string getMaxKey() {
        // if(counts.size() == 0){
        if(mSearch.size() == 0){
            return "";
        }
        // string str = *(mSearch[*(counts.rbegin())].begin());
        string str = *(((pair<int, set<string>>)*(mSearch.rbegin())).second.begin());
        // cout << counts << " " << *(counts.rbegin()) << endl << str << endl;
        // cout << mSearch[0] << endl << mSearch[1] << endl << mSearch[2] << endl;
        return str;
    }
    
    string getMinKey() {
        // if(counts.size() == 0){
        if(mSearch.size() == 0){
            return "";
        }
        // string str = *(mSearch[*(counts.begin())].begin());
        string str = *(((pair<int, set<string>>)*(mSearch.begin())).second.begin());
        // cout << counts << " " << *(counts.begin()) << endl << str << endl;
        return str;
    }
};


// 10 53;
class AllOne1 {
private:
    map<string, int> mCount;    // 字符串计数
    map<int, set<string>> mSearch;   // 计数和对应字符串
    set<int> counts; // 计数升序，最少在前，最多在后
public:
    AllOne1() {
        // cout << mSearch[0] << endl; // 默认？mSearch[0]={""};
    }
    
    void inc(string key) {
        auto it = mCount.find(key);
        if(it == mCount.end()){
            mCount.insert(make_pair(key, 1));
            mSearch[1].insert(key);
            counts.insert(1);
        }else{
            mSearch[mCount[key]].erase(key);
            if(mSearch[mCount[key]].size() == 0){
                counts.erase(mCount[key]);
            }
            mCount[key] += 1;
            counts.insert(mCount[key]);
            mSearch[mCount[key]].insert(key);
        }
    }
    
    void dec(string key) {
        // auto it = mCount.find(key);
        // if(it == mCount.end()){
        //     mCount.insert(make_pair(key, 1));
        //     mSearch[1].insert(key);
        //     counts.insert(1);
        // }else{
            mSearch[mCount[key]].erase(key);
            if(mSearch[mCount[key]].size() == 0){
                counts.erase(mCount[key]);
            }
            mCount[key] -= 1;
            if(mCount[key] > 0){
                counts.insert(mCount[key]);
                mSearch[mCount[key]].insert(key);
            }
        // }
    }
    
    string getMaxKey() {
        if(counts.size() == 0){
            return "";
        }
        string str = *(mSearch[*(counts.rbegin())].begin());
        // cout << counts << " " << *(counts.rbegin()) << endl << str << endl;
        // cout << mSearch[0] << endl << mSearch[1] << endl << mSearch[2] << endl;
        return str;
    }
    
    string getMinKey() {
        if(counts.size() == 0){
            return "";
        }
        string str = *(mSearch[*(counts.begin())].begin());
        // cout << counts << " " << *(counts.begin()) << endl << str << endl;
        return str;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

// @lc code=end

/*
["AllOne", "inc", "getMaxKey", "getMinKey", "dec", "getMaxKey", "getMinKey", "dec", "getMaxKey", "getMinKey"]\n[[], ["hello"], [], [], ["hello"], [], []]
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey", "dec", "getMaxKey", "getMinKey"]
\n[[], ["hello"], ["hello"], [], [], ["leet"], [], [], ["leet"], [], []]
["AllOne", "inc", "inc", "dec", "getMaxKey", "getMinKey"]\n[[],["hello"], ["world"],["hello"],[],[]]

["AllOne","inc","inc","inc","inc","inc","dec","dec","getMaxKey","getMinKey"]\n[[],["a"],["b"],["b"],["b"],["b"],["b"],["b"],[],[]]
*/