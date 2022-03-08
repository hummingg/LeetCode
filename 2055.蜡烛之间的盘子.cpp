/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    // 45 21; 13 21;
    /*
        1. 如何快速找到区间内的首尾蜡烛
        2. 如何快速计算区间内的盘子数
    */
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int sSize = s.size();
        vector<int> r;  // 待返回的结果
        // 快速找到区间内的首尾蜡烛
        int vn[sSize]; // 下一个盘子位置
        int vp[sSize]; // 上一个盘子位置
        // 快速计算区间内的盘子数
        map<int, int> m;
        int count = 0;
        int pre = -1;   // 上一个盘子位置
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '|'){
                pre = i;
                m.insert(make_pair(i, count));
            }else{
                count++;
            }
            vp[i] = pre;
        }
        int next = sSize;   // 下一个盘子位置
        for(int i = sSize - 1; i >= 0; i--){
            if(s[i] == '|'){
                next = i;
            }
            vn[i] = next;
        }
        for(int i = 0; i < queries.size(); i++){
            int begin = vn[queries[i][0]];
            int end = vp[queries[i][1]];

            if(begin < end){
                // r.push_back(v[end] - v[begin]);
                r.push_back(m[end] - m[begin]);
            }else{
                r.push_back(0);
            }

            // vector<int> query = queries[i];
            
            // 超时方法
            // while(begin < end && v[begin] == -1){
            //     begin++;
            // }
            // while(begin < end && v[end] == -1){
            //     end--;
            // }
            
            // 超时方法
            // for(int j = query[0]; j<=query[1]; j++){
            //     auto it = m.find(j);
            //     if(it != m.end()){
            //         begin = it->first;
            //         break;
            //     }
            // }
            // for(int j = query[1]; j>=query[0]; j--){
            //     auto it = m.find(j);
            //     if(it != m.end()){
            //         end = it->first;
            //         break;
            //     }
            // }
        }
        return r;
    }

    // Time Limit Exceeded
    vector<int> platesBetweenCandles1(string s, vector<vector<int>>& queries) {
        vector<int> v;
        string sstr;
        for(int i = 0; i<queries.size(); i++){
            sstr = s.substr(queries[i][0], queries[i][1]-queries[i][0]+1);
            // cout << sstr << endl;
            v.push_back(countPlate(sstr));
        }
        return v;
    }
    int countPlate(string s){
        int firstCandle = s.find_first_of('|');
        int lastCandle = s.find_last_of('|');
        // cout << firstCandle << " " << lastCandle << endl;
        int count = 0;
        for(int i = firstCandle + 1; i < s.size() && i < lastCandle; i++ ){
            if(s[i] == '*'){
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

