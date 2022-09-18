/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */
#include <iostream>
#include <vector>
#include <algorithm>
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
private:
    vector<int> ret;
public:
    // WA 所有可能组合,组合不能重复
    vector<int> diffWaysToCompute(string expression) {
        vector<int> vNum;
        vector<char> vOp;
        string str_num = "";
        int size = expression.size();
        for(int i = 0; i < size; ++i){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vNum.push_back(atoi(str_num.c_str()));
                vOp.push_back(expression[i]);
                str_num = "";
            }else{
                str_num += expression[i];
            }
        }
        vNum.push_back(atoi(str_num.c_str()));
        // cout << vNum << " " << vOp << endl;
        recursion(vNum, vOp);
        // ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }

    void recursion(vector<int> vNum, vector<char> vOp){
        int size = vOp.size();
        if(size == 0){
            ret.push_back(vNum[0]);
            return;
        }
        // cout << "开始" << vNum << " " << vOp << endl;
        for(int i = 0; i < size; ++i){
            // 处理 i 和 i+1 的操作数
            char c = vOp[i];
            int result = 0;
            switch(c){
                case '+':
                    result = vNum[i] + vNum[i+1];
                    break;
                case '-':
                    result = vNum[i] - vNum[i+1];
                    break;
                case '*':
                    result = vNum[i] * vNum[i+1];
                    break;
                default:
                    cout << "op error!" << endl;
                    break;
            }
            vector<int> vNum1 = vNum;
            vNum1[i] = result;
            vNum1.erase(vNum1.begin() + i + 1);
            vector<char> vOp1 = vOp;
            vOp1.erase(vOp1.begin() + i);
            // cout << "深入 " << vNum1 << " " << vOp1 << endl;
            recursion(vNum1, vOp1);
        }
    }
};
// @lc code=end
// int main(){
//     Solution s;
//     // vector<int> v = {1, 2};
//     string str = "2-1-1";
//     cout << s.diffWaysToCompute(str) << endl;
//     return 0;
// }
/*
'"2-1-1"\n
"2*3-4*5"'

(2*(3-(4*5))) = -34     321
((2*3)-(4*5)) = -14     132
((2*(3-4))*5) = -10     213
(2*((3-4)*5)) = -10     231
(((2*3)-4)*5) = 10      123
((2*3)-(4*5)) = -14     312? 要去重！
312 跟 132 一样，平等地位

2 1 1 - -
2 3 4 5 || * - *


*/