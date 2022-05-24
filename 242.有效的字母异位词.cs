using System;
using System.Collections.Generic;
/*
 * @lc app=leetcode.cn id=242 lang=csharp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.24%)
 * Likes:    563
 * Dislikes: 0
 * Total Accepted:    408.2K
 * Total Submissions: 625.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
public class Solution {
    // 28 60;
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length){
            return false;
        }
        var dict = new Dictionary<Char, int>();
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
                if(dict[c] < 0){
                    return false;
                }
            }else{
                return false;
            }
        }
        foreach(var kvp in dict){
            if(kvp.Value != 0){
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

