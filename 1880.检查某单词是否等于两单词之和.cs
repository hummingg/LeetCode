using System.Text;
using System;
/*
 * @lc app=leetcode.cn id=1880 lang=csharp
 *
 * [1880] 检查某单词是否等于两单词之和
 */
 
// @lc code=start
public class Solution {
    // 50 31 72 37.4;
    public bool IsSumEqual(string firstWord, string secondWord, string targetWord) {
        int L = firstWord.Length, M = secondWord.Length, N = targetWord.Length;
        // 对齐
        int size = Math.Max(L, Math.Max(M, N));
        var sb1 = new StringBuilder(firstWord);
        var sb2 = new StringBuilder(secondWord);
        var sb3 = new StringBuilder(targetWord);
        sb1.Insert(0, "a", size - L);
        sb2.Insert(0, "a", size - M);
        sb3.Insert(0, "a", size - N);
        int i = size - 1;
        int partSum = 0, carry = 0;
        while(i >= 0){
            partSum = LetterAdd(sb1[i], sb2[i]) + carry;
            carry = partSum / 10;
            if(partSum % 10 != GetInt(sb3[i])){
                return false;
            }
            --i;
        }
        return carry == 0;
    }

    int LetterAdd(char a, char b){
        // 0 48 a 97
        return GetInt(a) + GetInt(b);
    }

    int GetInt(char a){
        return a - 97;
    }
}
// @lc code=end
/*
'"acb"\n"cba"\n"cdb"\n
"aaa"\n"a"\n"aab"\n
"aaa"\n"a"\n"aaaa"'
*/
