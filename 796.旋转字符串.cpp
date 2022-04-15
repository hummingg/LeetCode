/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
public:
    // 100 66;
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        int size = s.size();
        int begin = 0;
        for(; begin < size; ++begin){
            int j = 0;
            for(; j < size; ++j){
                if(s[(j+begin) % size] != goal[j]){
                    break;
                }
            }
            if(j == size){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
/*
"abcde"\n"cdeab"
""abcde"\n"abced""
*/
