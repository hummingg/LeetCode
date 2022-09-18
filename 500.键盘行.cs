/*
 * @lc app=leetcode.cn id=500 lang=csharp
 *
 * [500] 键盘行
 *
 * https://leetcode.cn/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (74.43%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    58.5K
 * Total Submissions: 78.6K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 美式键盘 中：
 * 
 * 
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 * 输出：["Alaska","Dad"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["omk"]
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["adsdf","sfd"]
 * 输出：["adsdf","sfd"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * words[i] 由英文字母（小写和大写字母）组成
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 86 61 144 43.5;
    public string[] FindWords(string[] words) {
        string[] lines = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        List<string> ls = new List<string>();
        foreach(var word in words){
            int idx = -1;
            for (var i = 0; i < 3; i++){
                if(lines[i].IndexOf(char.ToLower(word[0])) > -1){
                    idx = i;
                    break;
                }
            }
            bool flag = true;
            foreach(var c in word){
                if(lines[idx].IndexOf(char.ToLower(c)) == -1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ls.Add(word);
            }
        }
        return ls.ToArray();
    }
}
// @lc code=end

