/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> m;
        for(int i = 0; i < groupSizes.size();i++){
            int size = groupSizes[i];
            auto it = m.find(size);
            if(it != m.end()){
                m[size].push_back(i);
            }else{
                m.insert(pair<int, vector<int>>(size, {i}));
            }
        }

        vector<vector<int>> vv;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            int key = it->first;
            vector<int>& value = m[key];
            vector<int> v;
            int count = 0;
            while(count < value.size()){
                for(int i = 0; i<key; i++){
                    v.push_back(value[count+i]);
                }
                vv.push_back(v);
                v.clear();
                count += key;
            }
        }
        return vv;
    }
};
// @lc code=end

