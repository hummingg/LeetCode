/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 *
 * https://leetcode-cn.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (53.51%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 45.6K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
 * 
 * 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
 * 
 * 
 * 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
 * 
 * 
 * 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。
 * 
 * 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
 * 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
 * 
 * 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入："AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入："AACCGGTT"\n"AAACGGTA", bank =
 * ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入："AAAAACCC"\n"AACCCCCC", bank =
 * ["AAAACCCC","AAACCCCC","AACCCCCC"]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * start.length == 8
 * end.length == 8
 * 0 <= bank.length <= 10
 * bank[i].length == 8
 * start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
 * 
 * 
 */

// @lc code=start
class Solution {
    map<string, set<string>> m;
    map<string, bool> flags;
    string end;
    int ret = INT_MAX;
public:
    // 100 5;
    int minMutation(string start, string end, vector<string>& bank) {
        this->end = end;
        for(auto g1 : bank){
            for(auto g2 : bank){
                int count = 0;
                for(int i = 0; i < 8 && count < 2; ++i){
                    count += g1[i] != g2[i];
                }
                // cout << g1 << " " << g2 << " " << count << endl;
                if(count == 1){
                    m[g1].insert(g2);
                    m[g2].insert(g1);
                }
            }
        }
        // for(auto [k, v] : m){
        //     cout << k << ": " <<  endl;
        //     for(auto s : v){
        //         cout << s << " ";
        //     }
        //     cout << endl;
        // }
        for(auto g2 : bank){
            int count = 0;
            for(int i = 0; i < 8 && count < 2; ++i){
                count += start[i] != g2[i];
            }
            // cout << start << " " << g2 << " " << count << endl;
            if(count == 1){
                m[start].insert(g2);
                m[g2].insert(start);
            }
        }

        // flags[start] = true;
        // dfs(start, 0);
        // return ret == INT_MAX ? -1 : ret;

        return bfs(start);  
    }

    void dfs(string str, int count){
        if(str == end){
            ret = min(ret, count);
            return;
        }
        for(auto nxt : m[str]){
            if(!flags[nxt]){
                flags[nxt] = true;
                dfs(nxt, count+1);
                flags[nxt] = false; // 回溯
            }
        }
    }

    // 100 5;
    int bfs(string start){
        queue<string> q;
        q.push(start);
        flags[start] = true;
        int count = 0;
        while(!q.empty()){
            queue<string> tmp;
            while(!q.empty()){
                string source = q.front();
                q.pop();
                if(source == end){
                    return count;
                }
                for(auto nxt : m[source]){
                    if(!flags[nxt]){
                        tmp.push(nxt);
                        flags[nxt] = true;
                    }
                }
                // if(tmp.empty()){
                //     return -1;
                // }
            }
            q = tmp;
            ++count;
        }
        return -1;
    }
};
// @lc code=end
/*
"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]\n
"AACCGGTT"\n"AAACGGTA"\n["AACCGGTA","AACCGCTA","AAACGGTA"]\n
"AAAAACCC"\n"AACCCCCC"\n["AAAACCCC","AAACCCCC","AACCCCCC"]\n
"AAAAACCC"\n"AACCCCCC"\n["AAAACCCC","AACCCCCC"]
*/
