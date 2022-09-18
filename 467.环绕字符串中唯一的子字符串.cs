using System;
using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=467 lang=csharp
 *
 * [467] 环绕字符串中唯一的子字符串
 *
 * https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (44.86%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    14.7K
 * Total Submissions: 31K
 * Testcase Example:  '"a"'
 *
 * 把字符串 s 看作是 “abcdefghijklmnopqrstuvwxyz” 的无限环绕字符串，所以 s 看起来是这样的：
 * 
 * 
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...." . 
 * 
 * 
 * 现在给定另一个字符串 p 。返回 s 中 唯一 的 p 的 非空子串 的数量 。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: p = "a"
 * 输出: 1
 * 解释: 字符串 s 中只有一个"a"子字符。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: p = "cac"
 * 输出: 2
 * 解释: 字符串 s 中的字符串“cac”只有两个子串“a”、“c”。.
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: p = "zab"
 * 输出: 6
 * 解释: 在字符串 s 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= p.length <= 10^5
 * p 由小写英文字母构成
 * 
 * 
 */
new Solution().FindSubstringInWraproundString("zabccefghijkklmn");
// @lc code=start
public class Solution {
    // 100 14;
    public int FindSubstringInWraproundString(string p) {
        var dic = new Dictionary<int,int>();
        int i = 0;
        while(i < p.Length){
            int j = i;
            while(j < p.Length-1){
                if(p[j] - p[j+1] == -1 || p[j] - p[j+1] == 25){
                    ++j;
                }else{
                    break;
                }
            }
            if(dic.ContainsKey(p[i])){
                dic[p[i]] = Math.Max(dic[p[i]], j-i+1);
            }else{
                dic.Add(p[i], j-i+1);
            }
            i = j+1;
        }
        var arr = new int[26];  // 以 'a'+i 开头的子串的长度
        foreach(var kvp in dic){
            // Console.WriteLine((char)item.Key + " " + item.Value);
            for(i = 0; i < 26 && i < kvp.Value; ++i){
                char c = (char)((kvp.Key-'a' + i) % 26 + 'a');
                arr[c-'a'] = Math.Max(arr[c-'a'], kvp.Value - i);
            }
        }
        // foreach(var cnt in arr){
        //     Console.WriteLine($"{cnt}");
        // }
        // Console.WriteLine($"{arr.Sum()}");
        return arr.Sum();
    }
}
// @lc code=end
/*
'"a"\n
"cac"\n
"zab"\n
"zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd"'
*/
