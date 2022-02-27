/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    // 97 7; 80 77; 80 19; 45 16; 80 53;
    bool hasGroupsSizeX(vector<int>& deck) {
        int size = deck.size();
        if(size < 2){
            return false;
        }

        // 统计出现次数
        map<int, int> m;
        for(int i = 0; i < size; i++){
            int num = deck[i];
            if(m.find(num) != m.end()){
                m[num]++;
            }else{
                m.insert(make_pair(num, 1));
            }
        }
        
        // 收集不同出现次数及最小次数
        int minNum = 1e4 + 1;
        set<int> s;
        for(map<int,int>::iterator it = m.begin(); it != m.end(); it++){
            int count = (*it).second;
            if(count < minNum){
                minNum = count;
            }
            if(s.find(count) == s.end()){
                s.insert(count);
            }
        }
        
        // 计算所有次数的最大公约数
        // cout << minNum << endl;
        for(int i = 1; i <= minNum / 2; i++){
            if(minNum % i != 0){
                continue;
            }
            int commonFactor = minNum / i;
            set<int>::iterator it = s.begin();
            for(; it != s.end(); it++){
                // cout << (*it) << endl;
                if((*it) % commonFactor != 0){
                    break;
                }
            }
            if(it == s.end()){
                return true;
            }
        }

        return false;
    }
};
// n^2 n

// int main(){
//     Solution s;
//     // [1,2,3,4,4,3,2,1]
//     // [1,1,1,2,2,2,3,3]
//     vector<int> v = {1,1,1,2,2,2,3,3};
//     cout << s.hasGroupsSizeX(v) << endl;
//     return 0;
// }
// @lc code=end

