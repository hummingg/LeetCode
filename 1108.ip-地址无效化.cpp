/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    // 100 6; 100 97 0 5.7;
    string defangIPaddr(string address) {
        string ret;
        for(int i = 0; i < address.size(); i++){
            if(address[i] == '.'){
                ret += "[.]";
            }else{
                ret += address[i];
            }
        }
        return ret;
    }
};
// @lc code=end

