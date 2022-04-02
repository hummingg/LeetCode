/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
#include <numeric>
// #include <string>
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
    // 73 93;
    int calPoints(vector<string>& ops) {
        stack<int> stk;    // vector当栈用？
        int size = ops.size();
        for(int i = 0; i < size; ++i){
            if(ops[i] == "C"){
                stk.pop();
            }else if(ops[i] == "D"){
                stk.push(stk.top() * 2);
            }else if(ops[i] == "+"){
                int last1 = stk.top();
                stk.pop();
                int last2 = stk.top();
                stk.push(last1);
                stk.push(last2 + last1);
            }else{
                stk.push(atoi(ops[i].c_str()));
            }
        }
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
// @lc code=end
/*
["1","5","2","C","C","D","+"]
["1","D","D","D","D","D","C","C","C","C","C"]
*/
