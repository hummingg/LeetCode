/*
 * @lc app=leetcode.cn id=1528 lang=cpp
 *
 * [1528] 重新排列字符串
 */
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
// @lc code=start
class Solution {
public:
    // 原地
    // 100 50;
    string restoreString(string s, vector<int>& indices) {
        int size = s.size();
        for(int i = 0; i < size; ++i){
            s[i] = s[i] - 32;
        }
        // cout << s << endl;
        int count = 0;
        int i = 0;
        char pre = s[i]+32, tmp;
        while(count < size){
            // a 97 A 65
            if(s[indices[i]] >= 97){
                i = (i+1) % size;
                pre = s[i]+32;
                continue;
            }
            // cout << i << " " << indices[i] << endl;
            tmp = s[indices[i]] + 32;
            s[indices[i]] = pre;
            i = indices[i];
            pre = tmp;
            // cout << s << endl;
            ++count;
        }
        // cout << pre << endl;
        return s;
    }

    // 59 84;
    string restoreString1(string s, vector<int>& indices) {
        int size = s.size();
        string ret;
        ret.resize(size);
        for(int i = 0; i < size; ++i){
            ret[indices[i]] = s[i];
        }
        return ret;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {4,5,6,7,0,2,1,3};
    cout << s.restoreString("codeleet", v) << endl;
    return 0;
}
/*
"codeleet"\n[4,5,6,7,0,2,1,3]\n
"abc"\n[0,1,2]\n
"abc"\n[1,0,2]
*/
