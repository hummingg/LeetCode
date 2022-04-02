/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
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
    // 95 87;
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        int count = 0;
        int num = 1;
        int base = 0;
        while(count < n){
            while(num <= n){
                ret.push_back(num);
                ++count;
                num *= 10;  // 1090
            };
            num = num / 10 + 1; // 回退到110，但11还没进来
            if(num % 10 == 0){  // 110应由 11*10 得到，不应由回退得到
                do{
                    num = num / 10;
                }while(num % 10 == 0);
                continue;
            }
            base = num / 10;
            while(num <= n && num/10 == base){
                ret.push_back(num);
                ++count;
                ++num;
            }
            
            // 回退要补全
            if(num % 10 == 0){
                do{
                    num = num / 10; // 个位的0应由 *10 得到，不应由回退、增加得到
                }while(num % 10 == 0);
            }else{  // 较少，如例13. 14 -> 2 
                num = num / 10 + 1; // 回退。什么时候回退到个位数？
                if(num % 10 == 0){  // 110应由 11*10 得到，不应由回退得到
                    do{
                        num = num / 10;
                    }while(num % 10 == 0);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<int> v = {1, 2};
    cout << s.lexicalOrder(9) << endl;
    return 0;
}
/*
50000
192
[0, 1] [0, 1, 2, 3]
01 *10 10 *10 100 *10 1000 1001 1002 /10+1 101 1010 1011 /10+1 102  11 12 13 14 15 16 17 18 19  20  
*10 +1 /10+1 *10 +1
19 199 ->2
   189 1890
*/
