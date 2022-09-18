using System;
using System.Text;
/*
 * @lc app=leetcode.cn id=43 lang=csharp
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.82%)
 * Likes:    945
 * Dislikes: 0
 * Total Accepted:    229.3K
 * Total Submissions: 511.5K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 96 44; 54 44 84 40.3;
    // static int NO = -1;
    // public Solution(){
    //     NO++;
    // }
    public string Multiply(string num1, string num2) {
        // Console.WriteLine($"{NO}");
        
        // num1 * num2 列竖式
        int len1 = num1.Length, len2 = num2.Length;
        var sbs = new StringBuilder[len2];
        int carry = 0;
        for(int i = len2-1; i >= 0; --i){
            sbs[i] = new StringBuilder();   // 头部要填充 len2-1-i 个0
            int digit2 = num2[i] - '0';
            carry = 0;
            for(int j = len1-1; j >= 0; --j){
                int digit1 = num1[j] - '0';
                int mult = digit1 * digit2 + carry;
                carry = mult / 10;
                sbs[i].Append(mult % 10);
            }
            if(carry > 0){
                sbs[i].Append(carry);
            }
            sbs[i].Insert(0, "0", len2-1-i);
        }
        int maxLen = 0;
        foreach(var sb in sbs){
            // Console.WriteLine($"{sb.ToString()}");
            maxLen = Math.Max(maxLen, sb.Length);
        }
        var sbRet = new StringBuilder();
        carry = 0;
        for(int i = 0; i < maxLen; ++i){
            int partSum = 0;
            foreach(var sb in sbs){
                if(i < sb.Length){
                    partSum += sb[i] - '0';
                }
            }
            partSum += carry;
            carry = partSum / 10;
            sbRet.Insert(0, partSum % 10);
        }
        if(carry > 0){
            sbRet.Insert(0, carry);
        }
        var strRet = sbRet.ToString();
        if(strRet.Replace("0", "").Length == 0){
            return "0";
        }
        return strRet;
    }
}
// @lc code=end
/*
'"2"\n"3"\n
"123"\n"456"\n
"9"\n"99"\n
"9133"\n"0"'
*/
