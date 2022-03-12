/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start
class Solution {
public:
    // 64 71;
    // 改动题目：不要求连续浇水，求最小步数
    int wateringPlants(vector<int>& plants, int capacity) {
        int mount = capacity;
        int sum = 0;
        int i = 0;  // i是下一朵要浇水的花
        while(true){
            while(i < plants.size() && mount >= plants[i]){
                mount -= plants[i++];
            }
            if(i == plants.size()){
                sum += i;
                return sum;
            }else{
                sum += i * 2;   // 这次走不到的第一个位置
            }
            mount = capacity;
        }
        return sum;
    }
};
// @lc code=end

