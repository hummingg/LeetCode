/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution {
public:
    // 54 5; 100 5;
    // 可以进一步节省2/3空间
    vector<int> shortestToChar(string s, char c) {
        int size = s.size();
        vector<int> pre(size), nxt(size);
        int cPos = INT_MAX;
        for(int i = 0; i < size; ++i){
            if(s[i] == c){
                cPos = i;
            }
            pre[i] = cPos;
        }
        cPos = INT_MAX;
        for(int i = size-1; i>=0; --i){
            if(s[i] == c){
                cPos = i;
            }
            nxt[i] = cPos;
        }
        vector<int> ret(size);
        for(int i = 0; i < size; ++i){
            ret[i] = min(abs(pre[i]-i), abs(nxt[i]-i));
        }
        return ret;
    }
};
// @lc code=end
/*
""loveleetcode"\n"e"\n
"aaab"\n"b""
*/
