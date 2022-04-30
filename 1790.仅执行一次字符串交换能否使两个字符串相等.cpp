/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
class Solution {
public:
    // 100 14;
    bool areAlmostEqual(string s1, string s2) {
        int count  = 0;
        vector<int> v;
        int size = s1.size();
        for(int i = 0; i < size; ++i){
            if(s1[i] != s2[i]){
                ++count;
                if(count > 2){
                    return false;
                }
                v.push_back(i);
            }
        }
        if(count == 0){
            return true;
        }else if(count == 1){
            return false;
        }
        return s1[v[0]] == s2[v[1]] && s1[v[1]] == s2[v[0]];
    }
};
// @lc code=end
/*
""attack"\n"defend"\n
"kelb"\n"kelb"\n
"eklb"\n"kelb"\n
"abcd"\n"dcba""
*/
