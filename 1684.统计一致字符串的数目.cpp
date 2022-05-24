/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
public:
    // 26 63;
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(auto str : words){
            bool consistent = true;
            for(int i = 0; i < str.size(); i++){
                bool in = false;
                for(int j = 0; j < allowed.size(); j++){
                    if(allowed[j] == str[i]){
                        in = true;
                        break;
                    }
                }
                if(!in){
                    consistent = false;
                    break;
                }
            }
            if(consistent){
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

