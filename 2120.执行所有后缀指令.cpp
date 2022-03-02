/*
 * @lc app=leetcode.cn id=2120 lang=cpp
 *
 * [2120] 执行所有后缀指令
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int hor[2], ver[2];
        ver[0] = -startPos[0];
        ver[1] = n - 1 - startPos[0];
        hor[0] = -startPos[1];
        hor[1] = n - 1 - startPos[1];
        vector<int> answer;
        for(int i = 0; i < s.size(); i++){
            int hor_count= 0, ver_count = 0;
            int count = 0;
            bool end = false;
            for(int j = i; j < s.size(); j++){
                switch (s[j]){
                    case 'L':
                        hor_count--;
                        if(hor_count < hor[0] || hor_count > hor[1]){
                            end = true;
                        }
                        break;
                    case 'R':
                        hor_count++;
                        if(hor_count < hor[0] || hor_count > hor[1]){
                            end = true;
                        }
                        break;
                    case 'U':
                        ver_count--;
                        if(ver_count < ver[0] || ver_count > ver[1]){
                            end = true;
                        }
                        break;
                    case 'D':
                        ver_count++;
                        if(ver_count < ver[0] || ver_count > ver[1]){
                            end = true;
                        }
                        break;
                    default:
                        break;
                }
                if(end){
                    break;
                }
                else{
                    count++;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};
// @lc code=end

