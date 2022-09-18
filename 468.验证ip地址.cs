using System;
using System.Runtime.Serialization;
using System.Text;
/*
 * @lc app=leetcode.cn id=468 lang=csharp
 *
 * [468] 验证IP地址
 *
 * https://leetcode.cn/problems/validate-ip-address/description/
 *
 * algorithms
 * Medium (25.93%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 138.1K
 * Testcase Example:  '"172.16.254.1"'
 *
 * 给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；如果是有效的 IPv6 地址，返回 "IPv6"
 * ；如果不是上述类型的 IP 地址，返回 "Neither" 。
 * 
 * 有效的IPv4地址 是 “x1.x2.x3.x4” 形式的IP地址。 其中 0 <= xi <= 255 且 xi 不能包含 前导零。例如:
 * “192.168.1.1” 、 “192.168.1.0” 为有效IPv4地址， “192.168.01.1” 为无效IPv4地址;
 * “192.168.1.00” 、 “192.168@1.1” 为无效IPv4地址。
 * 
 * 一个有效的IPv6地址 是一个格式为“x1:x2:x3:x4:x5:x6:x7:x8” 的IP地址，其中:
 * 
 * 
 * 1 <= xi.length <= 4
 * xi 是一个 十六进制字符串 ，可以包含数字、小写英文字母( 'a' 到 'f' )和大写英文字母( 'A' 到 'F' )。
 * 在 xi 中允许前导零。
 * 
 * 
 * 例如 "2001:0db8:85a3:0000:0000:8a2e:0370:7334" 和
 * "2001:db8:85a3:0:0:8A2E:0370:7334" 是有效的 IPv6 地址，而
 * "2001:0db8:85a3::8A2E:037j:7334" 和
 * "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 是无效的 IPv6 地址。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：queryIP = "172.16.254.1"
 * 输出："IPv4"
 * 解释：有效的 IPv4 地址，返回 "IPv4"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
 * 输出："IPv6"
 * 解释：有效的 IPv6 地址，返回 "IPv6"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：queryIP = "256.256.256.256"
 * 输出："Neither"
 * 解释：既不是 IPv4 地址，又不是 IPv6 地址
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * queryIP 仅由英文字母，数字，字符 '.' 和 ':' 组成。
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 85 67;
    public string ValidIPAddress(string queryIP) {
        int cntPeriod = 0, cntColon = 0;
        foreach(var c in queryIP){
            if(c == '.'){
                ++cntPeriod;
            }else if(c == ':'){
                ++cntColon;
            }
        }
        if(cntPeriod != 3 && cntColon != 7){
            return "Neither";
        }
        char sep = cntPeriod == 3 ? '.' : ':';
        var sb = new StringBuilder();
        string part = String.Empty;
        foreach(var c in queryIP){
            if(c == sep){
                part = sb.ToString();
                if(!Check(sep, part)){
                    return "Neither";
                }
                sb = new StringBuilder();
                continue;
            }
            sb.Append(c);
        }
        part = sb.ToString();
        if(!Check(sep, part)){
            return "Neither";
        }
        return sep == '.' ? "IPv4" : "IPv6";
    }
    public bool Check(char sep, string part){
        if(sep == '.'){
            if(part.Length == 0 || part.Length > 3 || part.Length > 1 && part[0] == '0'){
                return false;
            }
            int partNum;
            bool isNumber = int.TryParse(part, out partNum);
            if(!isNumber || partNum < 0 || partNum > 255){
                return false;
            }
        }else{
            if(part.Length == 0 || part.Length > 4){
                return false;
            }
            foreach(var cc in part){
                if(!(('0' <= cc && cc <= '9') || ('a' <= cc && cc <= 'f') || ('A' <= cc && cc <= 'F'))){
                    return false;
                }
            }
        }
        return true;
    }
}
// @lc code=end
/*
'"172.16.254.1"\n
"2001:0db8:85a3:0:0:8A2E:0370:7334"\n
"256.256.256.256"\n
"192.168.1.1"\n
"192.168.1.0"\n
"192.168.01.1"\n
"192.168.1.00"\n
"2001:0db8:85a3:0000:0000:8a2e:0370:7334"\n
"2001:db8:85a3:0:0:8A2E:0370:7334"\n
"2001:0db8:85a3::8A2E:037j:7334"\n
"02001:0db8:85a3:0000:0000:8a2e:0370:7334"'
*/

// "192.168@1.1"\n
