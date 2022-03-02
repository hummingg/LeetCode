/*
 * @lc app=leetcode.cn id=1409 lang=cpp
 *
 * [1409] 查询带键的排列
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    // 45 24; 45 60;
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> results;
        for(int i = 0; i < queries.size(); i++){
            // error: variable-sized object may not be initialized
            bool flags[m+1];
            for(int i = 0; i < m+1; i++){
                flags[i] =  false;
            }
            // vector<bool> flags(m+1, false);
            int num_i = queries[i];
            int j = i-1;
            for(; j > -1; j--){
                int num_j = queries[j];
                flags[num_j] = true;
                if(num_j == num_i){
                    break;
                }
            }
            
            int k = m;
            int count = 0;
            if(j == -1){
                // 大于 queries[i] 的个数
                while(k>num_i){
                    if(flags[k]){
                        count++;
                    }
                    k--;
                }
                results.push_back(num_i - 1 + count);
            }else{
                // 前一个 queries[i]后，出现的所有不同数字的个数
                while(k>0){
                    if(flags[k] && k!=num_i){   // 必然不等于
                        count++;
                    }
                    k--;
                }
                results.push_back(count);
            }
        }
        return results;
    }

    // 7 5;
    // 参数 m 无用
    vector<int> processQueries1(vector<int>& queries, int m) {
        vector<int> results;
        for(int i = 0; i < queries.size(); i++){
            int num_i = queries[i];
            set<int> biggers;   // 前面没出现过，则被使用
            set<int> prevs; // 前面出现过，则被使用
            int j = i-1;
            for(; j > -1; j--){
                int num_j = queries[j];
                if(num_j == num_i){
                    results.push_back(prevs.size());
                    break;
                }else{
                    if(num_j > num_i){
                        biggers.insert(num_j);
                    }
                    prevs.insert(num_j);
                }
            }
            if(j == -1){
                results.push_back(num_i - 1 + biggers.size());
            }
        }
        return results;
    }
};
// @lc code=end

