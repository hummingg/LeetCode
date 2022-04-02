/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
class Solution {
public:
    // 65 64;
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(auto str : operations){
            if(str == "X++" || str == "++X"){
                count++;
            }else{
                count--;
            }
        }
        return count;
    }
};
// @lc code=end

