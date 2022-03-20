/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 100 58;
    vector<int> partitionLabels(string s) {
        vector<int> v;
        int pos_first[26]; // 0对应a，保存第一个位置
        fill_n(pos_first, 26, 500);
        // cout << pos_first[0] << " " << pos_first[1] << endl;
        int pos_last[26]; // 0对应a，保存最后一个位置
        fill_n(pos_last, 26, -1);
        for(int i=0; i < s.size(); i++){
            int index = s[i]-'a';
            if(pos_first[index] > i){
                pos_first[index] = i;
            }
            if(pos_last[index] < i){
                pos_last[index] = i;
            }
        }
        // 合并各字母区间
        for(int i = 0; i < s.size();){
            int index = s[i]-'a';
            int begin = pos_first[index];   // 必然不等于500
            // cout << s[i] << pos_first[index] << endl;
            int end = pos_last[index];  // 必然不等于-1
            for(int j = begin+1; j < end; j++){
                int index_1 = s[j]-'a';
                // int begin_1 = pos_first[index];
                int end_1 = pos_last[index_1];
                end = max(end, end_1);  // 拉长区间
            }
            // cout << "begin "<< begin << " end " << end << endl;
            v.push_back(end-begin+1);
            i = end+1;
        }
        return v;
    }
};
// @lc code=end

