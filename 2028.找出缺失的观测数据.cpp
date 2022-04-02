/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
public:
    // 100 95;
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m+n) - accumulate(rolls.begin(), rolls.end(), 0);
        double avg = 1.0 * sum / n;
        if(avg > 6 || avg < 1){
            return {};
        }
        int base = avg;
        vector<int> ret(n, base);
        sum = sum - base * n;
        for(int i = 0; i < n; ++i){
            if(sum > 0){
                ++ret[i];
                --sum;
            }else{
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
/*
[3,2,4,3]\n4\n2
[1,5,6]\n3\n4
[1,2,3,4]\n6\n4
[1]\n3\n1
[3,5,3]\n5\n3
*/
