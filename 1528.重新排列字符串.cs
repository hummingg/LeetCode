using System.Text;
/*
 * @lc app=leetcode.cn id=1528 lang=csharp
 *
 * [1528] 重新排列字符串
 *
 * https://leetcode.cn/problems/shuffle-string/description/
 *
 * algorithms
 * Easy (78.62%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    33.7K
 * Total Submissions: 42.8K
 * Testcase Example:  '"codeleet"\n[4,5,6,7,0,2,1,3]'
 *
 * 给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
 * 
 * 请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
 * 
 * 返回重新排列后的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
 * 输出："leetcode"
 * 解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abc", indices = [0,1,2]
 * 输出："abc"
 * 解释：重新排列后，每个字符都还留在原来的位置上。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * s.length == indices.length == n
 * 1 <= n <= 100
 * s 仅包含小写英文字母
 * 0 <= indices[i] < n
 * indices 的所有的值都是 唯一 的
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 33 57; 14 100; 100 95;
    public string RestoreString(string s, int[] indices) {
        int size = s.Length;
        var sb = new StringBuilder(size);
        int i = 0;
        for(; i < size; ++i){
            // sb[i] = (char)(s[i] - 32);   // 错误
            sb.Append((char)(s[i] - 32));   // 先转为大写
        }
        int count = 0;
        i = 0;
        char pre = (char)(sb[i]+32), tmp;
        while(count < size){
            // a 97 A 65
            if(sb[indices[i]] >= 97){
                i = (i+1) % size;
                pre = (char)(sb[i]+32);
                continue;
            }
            tmp = (char)(sb[indices[i]] + 32);
            sb[indices[i]] = pre;
            i = indices[i];
            pre = tmp;
            ++count;
        }
        return sb.ToString();
    }
    // 100 81;
    public string RestoreString1(string s, int[] indices) {
        int size = s.Length;
        var sb = new StringBuilder(size);
        sb.Insert(0, "A", size);
        // Console.WriteLine($"{sb.ToString()}");
        for(int i = 0; i < size; ++i){
            sb[indices[i]] = s[i];
        }
        return sb.ToString();
    }
}
// @lc code=end

