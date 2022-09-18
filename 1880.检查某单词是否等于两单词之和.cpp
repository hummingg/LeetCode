/*
 * @lc app=leetcode.cn id=1880 lang=cpp
 *
 * [1880] 检查某单词是否等于两单词之和
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
    // 100 97 0 5.6;
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int L = firstWord.size(), M = secondWord.size(), N = targetWord.size();
        // 对齐
        int size = max({L, M, N});
        firstWord.insert(0, size - L, 'a');
        secondWord.insert(0, size - M, 'a');
        targetWord.insert(0, size - N, 'a');
        int i = size - 1;
        int partSum = 0, carry = 0;
        while(i >= 0){
            partSum = letterAdd(firstWord[i], secondWord[i]) + carry;
            carry = partSum / 10;
            if(partSum % 10 != getInt(targetWord[i])){
                return false;
            }
            --i;
        }
        return carry == 0;
    }
    
    bool isSumEqual1(string firstWord, string secondWord, string targetWord) {
        int m = firstWord.size(), n = secondWord.size(), p = targetWord.size();
        int i = m - 1, j = n - 1, k = p - 1;
        int partSum = 0, carry = 0;
        while(i >= 0 && j >= 0 && k >= 0){
            partSum = letterAdd(firstWord[i], secondWord[j]) + carry;
            carry = partSum / 10;
            if(partSum % 10 != getInt(targetWord[k])){
                return false;
            }
            --i;
            --j;
            --k;
        }
        while(k >= 0 && i >= 0){
            partSum = getInt(firstWord[i]) + carry;
            carry = partSum / 10;
            if(partSum % 10 != getInt(targetWord[k])){
                return false;
            }
            --i;
            --k;
        }
        while(k >= 0 && j >= 0){
            partSum = getInt(secondWord[j]) + carry;
            carry = partSum / 10;
            if(partSum % 10 != getInt(targetWord[k])){
                return false;
            }
            --j;
            --k;
        }
        while(k >= 0){
            if(targetWord[k] != 'a' + carry){
                return false;
            }
            carry = 0;
            --k;
        }
        return i == -1 && j == -1 && k == -1;
    }

    int letterAdd(char a, char b){
        // 0 48 a 97
        return getInt(a) + getInt(b);
    }

    int getInt(char a){
        return a - 97;
    }
};
// @lc code=end
/*
'"acb"\n"cba"\n"cdb"\n
"aaa"\n"a"\n"aab"\n
"aaa"\n"a"\n"aaaa"'
*/
