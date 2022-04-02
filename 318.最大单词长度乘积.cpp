/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <bitset>
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
    // 52 72;
    int maxProduct(vector<string>& words) {
        int size = words.size();
        bitset<26> maxBits;
        // unsigned long maxValue = maxBits.set().to_ulong();
        // cout << maxValue << endl;
        unsigned long maxValue = (unsigned long)(1 << 26) - 1;
        // cout << (1 << 26) << " " << pow(2, 26) << endl; // 相等
        vector<bitset<26>> vvb(size);
        for(int i = 0; i < size; i++){
            vvb[i].set();   // 全1
            int count = 0;  // 长达1000
            for(int j = 0; j < words[i].size(); ++j){
                int idx = words[i][j]-'a';
                if(vvb[i][idx] == 1){
                    vvb[i].set(idx, 0); // 0表示出现过
                    ++count;
                    if(count == 26){
                        break;
                    }
                }
            }
            // cout << vvb[i].to_string() << endl;
        }
        int maxPrd = 0;
        for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size; ++j){
                // 不能出现两个都0，或运算
                // cout << vvb[i].to_string() << endl;
                // cout << vvb[j].to_string() << endl;
                // unsigned long value = vvb[i].to_ulong() | vvb[j].to_ulong();
                // cout << value << endl;
                // cout << bitset<26>(value).to_string() << endl;
                if((vvb[i].to_ulong() | vvb[j].to_ulong()) == maxValue){
                    maxPrd = max(maxPrd, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return maxPrd;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<string> v = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << s.maxProduct(v) << endl;
    return 0;
}
/*
"abcw","baz","foo","bar","xtfn","abcdef"
"a","ab","abc","d","cd","bcd","abcd"
"a","aa","aaa","aaaa"
*/