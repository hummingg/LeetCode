/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
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
    // 进阶 100 54; 100 40;
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5){
            n /= 5;
            count += n;
        }
        return count;
    }
};
// @lc code=end
int main(){
    Solution s;
    cout << s.trailingZeroes(10000) << endl;
    return 0;
}
