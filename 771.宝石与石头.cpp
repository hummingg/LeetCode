/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    // 100 56;
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        set<char> st;
        for(int i = 0; i < jewels.size(); i++){
            st.insert(jewels[i]);
        }
        for(int j = 0; j < stones.size(); j++){
            if(st.find(stones[j]) != st.end()){
                // ++m[stones[j]];
                ++count;
            }
        }
        return count;
    }

    // 100 84;
    int numJewelsInStones1(string jewels, string stones) {
        int count = 0;
        for(int i = 0; i < jewels.size(); i++){
            for(int j = 0; j < stones.size(); j++){
                if(jewels[i] == stones[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

