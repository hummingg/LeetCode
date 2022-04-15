/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    // 80 6;
    char nextGreatestLetter(vector<char>& letters, char target) {
        // a 97 z 122  123 -> 97
        //   0     25   26->0
        // char gt = (target + 1 - 97) % 26 + 'a';
        for(int i = 0; i < letters.size(); ++i){
            if(letters[i] > target){
                return letters[i];
            }
        }
        return letters[0];
    }

    // 44 70;
    char nextGreatestLetter1(vector<char>& letters, char target) {
        // a 97 z 122  123 -> 97
        //   0     25   26->0
        char gt = (target + 1 - 97) % 26 + 'a';
        for(int i = 0; i < letters.size(); ++i){
            if(letters[i] >= gt){
                return letters[i];
            }
        }
        return letters[0];
    }
};
// @lc code=end
/*
["a", "b"]\n"z"
["c", "f", "j"]\n"a"
["c","f","j"]\n"c"
["c","f","j"]\n"d"
["c","f","j"]\n"j"
*/
