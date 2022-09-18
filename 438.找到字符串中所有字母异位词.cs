/*
 * @lc app=leetcode.cn id=438 lang=csharp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.58%)
 * Likes:    902
 * Dislikes: 0
 * Total Accepted:    189.9K
 * Total Submissions: 347.9K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 81 11; 42 12 136 50.1;
    public IList<int> FindAnagrams(string s, string p) {
        var ret = new List<int>();
        int count = 0;
        var current = new int[26];
        var target = new int[26];
        foreach(var c in p){
            target[c-'a']++;
        }
        // Console.WriteLine($"{string.Join(',', target)}");
        for(int i = 0; i < s.Length; ++i){
            int idx = s[i]-'a';
            if(target[idx] == 0){   // 混入了不要的，子串全灭
                current = new int[26];
                count = 0;
                continue;
            }
            if(current[idx] == target[idx]){    // 达到上限了，去掉头部
                if(count > 0){
                    --current[s[i-count]-'a'];
                    --count;
                    --i;    // 重新判断
                }
                // Console.WriteLine($"{s[i]} {count} {string.Join(',', current)}");
                continue;
            }
            ++current[idx];
            ++count;
            // Console.WriteLine($"{s[i]} {count} {string.Join(',', current)}");
            if(count == p.Length){
                ret.Add(i-count+1);
                --current[s[i-count+1]-'a'];
                --count;
            }
        }
        return ret;
    }
}
// @lc code=end
/*
'"cbaebabacd"\n"abc"\n
"abab"\n"ab"'
*/
