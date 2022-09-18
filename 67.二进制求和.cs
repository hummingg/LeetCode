using System.Text;
/*
 * @lc app=leetcode.cn id=67 lang=csharp
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.84%)
 * Likes:    818
 * Dislikes: 0
 * Total Accepted:    250.6K
 * Total Submissions: 465.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 86 75; 64 71 76 37.8;
    public string AddBinary(string a, string b) {
        int i = a.Length-1, j = b.Length - 1;
        var sb = new StringBuilder();
        bool carry = false;
        while(i >= 0 && j >= 0){
            if(carry){
                if(a[i] == '1' || b[j] == '1'){
                    carry = true;
                    if(a[i] == '1' && b[j] == '1'){
                        sb.Insert(0, '1');
                    }else{
                        sb.Insert(0, '0');
                    }
                }else{
                    carry = false;
                    sb.Insert(0, '1');
                }
            }else{
                if(a[i] == '1' && b[j] == '1'){
                    carry = true;
                    sb.Insert(0, '0');
                }else{
                    carry = false;
                    sb.Insert(0, a[i]-'0' + b[j]-'0');  // ?
                }
            }
            --i;
            --j;
        }
        while(i >= 0){
            if(carry){
                if(a[i] == '1'){
                    sb.Insert(0, '0');
                }else{
                    carry = false;
                    sb.Insert(0, '1');
                }
            }else{
                sb.Insert(0, a[i]);
            }
            --i;
        }
        while(j >= 0){
            if(carry){
                if(b[j] == '1'){
                    sb.Insert(0, '0');
                }else{
                    carry = false;
                    sb.Insert(0, '1');
                }
            }else{
                sb.Insert(0, b[j]);
            }
            --j;
        }
        if(carry){
            sb.Insert(0, '1');
        }
        return sb.ToString();
    }
}
// @lc code=end
/*
'"11"\n"1"\n
"1010"\n"1011"'
*/
