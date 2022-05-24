using System.Linq;
using System.Collections.Generic;
using System;
/*
 * @lc app=leetcode.cn id=389 lang=csharp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (68.44%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    125.5K
 * Total Submissions: 183.4K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t ，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "", t = "y"
 * 输出："y"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 70 83;
    public char FindTheDifference(string s, string t) {
        var dict = new Dictionary<char, int>();
        foreach(var c in s){
            if(dict.ContainsKey(c)){
                ++dict[c];
            }else{
                dict.Add(c, 1);
            }
        }
        foreach(var c in t){
            if(dict.ContainsKey(c)){
                --dict[c];
                if(dict[c] == -1){
                    return c;
                }
            }else{
                return c;
            }
        }
        return dict.Keys.First();    // 不会执行到
    }
}
// @lc code=end

