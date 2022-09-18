/*
 * @lc app=leetcode.cn id=1941 lang=cpp
 *
 * [1941] 检查是否所有字符出现次数相同
 */

// @lc code=start
class Solution {
    // 65 59 4 6.6;
public:
    bool areOccurrencesEqual(string s) {
        vector<int> v(26, 0);
        set<int> st;
        for(int i = 0; i < s.size(); ++i){
            int idx = s[i]-'a';
            st.insert(idx);
            ++v[idx];
        }
        int avg = s.size() / st.size();
        for(int i = 0; i < 26; ++i){
            if(v[i] != 0 && v[i] != avg){
                return false;
            } 
        }
        return true;
    }
};
// @lc code=end

