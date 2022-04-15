/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    // 15 21; 
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ret = 0;
        for(int i = 0; i < items.size(); i++){
            if(match(items[i], ruleKey, ruleValue)){
                ++ret;
            }
        }
        return ret;
    }

    bool match(vector<string> vs, string ruleKey, string ruleValue){
        if(ruleKey == "type"){
            return vs[0] == ruleValue;
        }else if(ruleKey == "color"){
            return vs[1] == ruleValue;
        }else if(ruleKey == "name"){
            return vs[2] == ruleValue;
        }
        return false;
    }
};
// @lc code=end

