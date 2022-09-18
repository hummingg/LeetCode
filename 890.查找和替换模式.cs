/*
 * @lc app=leetcode.cn id=890 lang=csharp
 *
 * [890] 查找和替换模式
 *
 * https://leetcode.cn/problems/find-and-replace-pattern/description/
 *
 * algorithms
 * Medium (73.11%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 14K
 * Testcase Example:  '["abc","deq","mee","aqq","dkd","ccc"]\n"abb"'
 *
 * 你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。
 * 
 * 如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。
 * 
 * （回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）
 * 
 * 返回 words 中与给定模式匹配的单词列表。
 * 
 * 你可以按任何顺序返回答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * 输出：["mee","aqq"]
 * 解释：
 * "mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
 * "ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
 * 因为 a 和 b 映射到同一个字母。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 50
 * 1 <= pattern.length = words[i].length <= 20
 * 
 * 
 */

// @lc code=start
public class Solution {
    // 100 100;
    public IList<string> FindAndReplacePattern(string[] words, string pattern) {
        char[] func;
        bool[] flags;
        int size = pattern.Length;
        var ret = new List<string>();
        foreach(var word in words){
            func = new char[26];    // 默认 '\0'
            flags = new bool[26];   // 默认 false
            int i = 0;
            for(; i < size; ++i){
                char c = word[i], p = pattern[i];
                if(func[p-'a'] == '\0'){    // p尚未映射
                    if(flags[c-'a']){   // c已被映射
                        break;
                    }
                    func[p-'a'] = c;
                    flags[c-'a'] = true;
                }else if(func[p-'a'] != c){ // 已经映射其他字母
                    break;
                }
            }
            if(i == size){
                ret.Add(word);
            }
        }
        return ret;
    }
}
// @lc code=end

