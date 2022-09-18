/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
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
    // 100 5 0 6.4;
public:
    // 第一个6变成9
    int maximum69Number (int num) {
        int digits = log10(num) + 1;
        int oldNum = num;
        stack<int> stk;
        do{
            stk.push(num % 10);
            num = num / 10;
        }while(num > 0);
        int pos = 0;
        while(!stk.empty()){
            int n = stk.top();
            if(n == 6){
                return oldNum + 3 * pow(10, digits-1 - pos);
            }
            ++pos;
            stk.pop();
        }
        return oldNum;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1, 2};
    cout << s.maximum69Number(9669) << endl;
    return 0;
}
