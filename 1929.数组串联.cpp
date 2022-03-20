/*
 * @lc app=leetcode.cn id=1929 lang=cpp
 *
 * [1929] 数组串联
 */
#include <iostream>
#include <vector>
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
    // 96 74;
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
        v.insert(v.end(), nums.begin(), nums.end());
        v.insert(v.end(), nums.begin(), nums.end());
        return v;
    }
};
// @lc code=end

