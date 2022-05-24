/*
 * @lc app=leetcode.cn id= lang=cpp
 *
 * 面试题 01.05. 一次编辑
 *
 * https://leetcode.cn/problems/one-away-lcci/description/
 *
 * algorithms
 * Medium (33.30%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    154.7K
 * Total Submissions: 52.3K
 * Testcase Example:  '"pale"\n"ple"'
 *
    字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 * 
 * 
示例 1:

输入: 
first = "pale"
second = "ple"
输出: True
 * 
 * 
示例 2:

输入: 
first = "pales"
second = "pal"
输出: False
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    // 60 15;
    bool oneEditAway(string first, string second) {
        if(first == second){
            return true;
        }
        int len1 = first.size(), len2 = second.size();
        if(abs(len1-len2) > 1){
            return false;
        }
        int left, right;    // 分别从左、右比较到第一个不同的second的位置
        int i = 0;
        while(i < len1 && i < len2 && first[i] == second[i]){
            ++i;
        }
        left = i;
        i = 1;
        while(i <= len1 && i <= len2 && first[len1-i] == second[len2-i]){
            ++i;
        }
        right = len2-i;
        if(len1 + 1 == len2 && (left == len2-1 || right == 0 || left == right)){    // 增：尾部、头部、中间
            return true;
        }else if(len1-1 == len2 && (left == len2 || right == -1 || left-1 == right)){   // 删：尾部、头部、中间
            return true;
        }else if(len1 == len2 && left == right){    // 改：尾部、头部、中间都一样
            return true;
        }
        return false;
    }
};
/*
"pale"
"ple"
"pales"
"pal"
"horse"
"ros"
"aab"
"aaab"
"aaab"
"aab"
"abb"
"aab"
"abc"
"aabc"
"abc"
"aabc"
"abc"
"abcc"
"abc"
"bc"
"abc"
"ac"
"abc"
"ab"
"abc"
"bbc"
"abc"
"aac"
"abc"
"abb"
""
"a"
"a"
""
*/