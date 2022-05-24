/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (73.41%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 44.9K
 * Testcase Example:  '"IDID"'
 *
 * 由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:
 * 
 * 
 * 如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
 * 如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
 * 
 * 
 * 给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含字符 "I" 或 "D"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 89 89;
    vector<int> diStringMatch(string s) {
        int size = s.size();
        int low = 0, high = size;
        vector<int> ret(size+1);
        for(int i = 0; i < size; ++i){
            if(s[i] == 'I'){
                ret[i] = low++;
            }else{
                ret[i] = high--;
            }
        }
        ret[size] = low;
        return ret;
    }

    // 89 90;
    vector<int> diStringMatch1(string s) {
        vector<int> v;
        char c = s[0];
        if(c == 'D'){
            v.push_back(0); // I D I D ...
        }
        int cntC = 1;
        for(int i = 1; i < s.size(); ++i){
            if(c == s[i]){
                ++cntC;
            }else{
                v.push_back(cntC);
                c = s[i];
                cntC = 1;
            }
        }
        v.push_back(cntC);
        // for(auto cnt : v){
        //     cout << cnt << " ";
        // }
        // cout << endl;
        int low = 0, high = s.size();
        vector<int> ret;
        int i = 0;
        for(; i < v.size()-1; i+=2){
            for(int j = 0; j < v[i]; ++j){  // I
                ret.push_back(low++);
            }
            for(int j = 0; j < v[i+1]; ++j){    // D
                ret.push_back(high--);
            }
        }
        if(i == v.size()-1){    // I
            for(int j = 0; j < v[i]; ++j){
                ret.push_back(low++);
            }
        }
        ret.push_back(low); // 剩下最后一个
        // for(auto cnt : ret){
        //     cout << cnt << " ";
        // }
        // cout << endl;

        return ret;
    }
};
// @lc code=end
/*
"IDID"
"III"
"DDD"
"DDI"
*/
