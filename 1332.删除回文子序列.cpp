/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
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
    // 100 90 0 5.9;
    // WA
    // 「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。
    // 「子序列」不要求连续，没看清题意
public:
    int removePalindromeSub(string s) {
        string old = s;
        reverse(s.begin(),s.end());
        return old == s ? 1 : 2;
    }

    int removePalindromeSub99(string s) {
        int count = 0;
        int size = s.size();
        int low = 0, high = size - 1;
        while(low <= high){
            int i, j;
            for(i = low, j = high; i < j; ++i, --j){
                if(s[i] != s[j]){
                    break;
                }
            }
            if(i >= j){
                low = high+1;
                high = size - 1;
                ++count;
            }else{
                --high;
            }
        }
        return count;
    }

    int removePalindromeSub9(string s) {
        int count = 0;
        while(s.size()){
            int size = s.size();
            for(int i = size-1; i >= 0; --i){
                if(isPali(s, i)){
                    s = s.substr(i+1);
                    ++count;
                    break;
                }
            }
        }
        return count;
    }

    bool isPali(string s, int end){
        int low = 0, high = end;
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1, 2};
    cout << s.removePalindromeSub("bbaabaaa") << endl;
    string str1 = "a";
    string str2(1, 'a');
    str2 = "b";
    cout << str1 << " " << str2 << " " << (str1 == str2) << endl;
    return 0;
}
/*
'"bbaabaaa"'
*/
