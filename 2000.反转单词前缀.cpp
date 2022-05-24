/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution {
    // 100 63;
public:
    string reversePrefix(string word, char ch) {
        int i=0, j=0, size = word.size();
        while(i < size && word[i] != ch){
            ++i;
        }
        if(i == size){
            return word;
        }
        int low = 0, high = i;
        while(low < high){
            char t = word[low];
            word[low] = word[high];
            word[high] = t;
            ++low;
            --high;
        }
        return word;
    }
};
// @lc code=end
/*
'"abcd"\n"z"'
*/
