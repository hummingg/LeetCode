/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
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
    // 100 72;
    bool hasAlternatingBits(int n) {
        unsigned long temp = 3UL * n;
        double dbl = log2(temp+1.0)/2;
        if(dbl - ceil(dbl) == 0){
            return true;
        }
        dbl = log2(temp/2.0+1)/2;
        return dbl - ceil(dbl) == 0;
    }

    // 100 69;
    bool hasAlternatingBits1(int n) {
        if(n == 0){
            return true;
        }
        int pre, cur = n % 2;
        do{
            pre = cur;
            n = n / 2;
            cur = n % 2;
            if(pre == cur){
                return false;
            }
        }while(n != 0); // 最高位是1，再高肯定是0
        return true;
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<int> v = {1, 2};
    cout << s.hasAlternatingBits(715827883) << endl;
    return 0;
}
/*
1结尾：1+4+16+...+2^(2n) = (4^(n+1)-1)/3
0结尾：2+8+32+...+2^(2n+1) = 2*(4^(n+1)-1)/3
*/
