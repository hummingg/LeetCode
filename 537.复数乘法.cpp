/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */
#include <iostream>
#include <string>
// #include <iterator>
using namespace std;
// template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
//     if (!v.empty()) {
//         out << '[';
//         std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
//         out << "]";
//     }
//     return out;
// }
// @lc code=start
class Solution {
public:
    // 100 88;
    string complexNumberMultiply(string num1, string num2) {
        // cout << "111111" << endl;
        int cmp1 = 0, cmpi1 = 0, cmp2 = 0, cmpi2 = 0;

        // 弄出 1 和 +号
        auto idx = num1.find_last_of("+i");
        if(idx != string::npos){
            num1.replace(idx, 2, "+1i");
        }
        idx = num1.find_last_of("-i");
        if(idx != string::npos){
            num1.replace(idx, 2, "-1i");
        }
        idx = num1.find_last_of("+-");
        if(idx == string::npos){
            idx = num1.find_last_of("-");
            if(idx != string::npos){
                num1.replace(idx, 1, "+-");
            }
        }
        // 圈数字
        idx = num1.find_first_of('+');
        if(idx != 0){
            cmp1 = atoi(num1.substr(0, idx).c_str());
        }
        auto idxi = num1.find_first_of('i');
        if(idxi != string::npos){
            cmpi1 = atoi(num1.substr(idx+1, idxi-idx-1).c_str());
        }
        // cout << cmp1 << " " << cmpi1 << endl;

        // 弄出 1 和 +号
        idx = num2.find_last_of("+i");
        if(idx != string::npos){
            num2.replace(idx, 2, "+1i");
        }
        idx = num2.find_last_of("-i");
        if(idx != string::npos){
            num2.replace(idx, 2, "-1i");
        }
        idx = num2.find_last_of("+-");
        if(idx == string::npos){
            idx = num2.find_last_of("-");
            if(idx != string::npos){
                num2.replace(idx, 1, "+-");
            }
        }
        // 圈数字
        idx = num2.find_first_of('+');
        if(idx != 0){
            cmp2 = atoi(num2.substr(0, idx).c_str());
        }
        idxi = num2.find_first_of('i');
        if(idxi != string::npos){
            cmpi2 = atoi(num2.substr(idx+1, idxi-idx-1).c_str());
        }
        // cout << cmp2 << " " << cmpi2 << endl;

        return to_string(cmp1*cmp2-cmpi1*cmpi2) + "+" + to_string(cmp1*cmpi2 + cmp2*cmpi1) + "i";
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<int> v = {1, 2};
    cout << s.complexNumberMultiply("1", "i") << endl;
    return 0;
}
/*
""1"\n"1""
""1"\n"i""
""1+1i"\n"1+1i""
""1+-1i"\n"1+-1i""
*/