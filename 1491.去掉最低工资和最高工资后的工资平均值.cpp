/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution {
public:
    // 100 97; 9 46;
    double average(vector<int>& salary) {
        int maxSalary = *max_element(salary.begin(), salary.end());
        int minSalary = *min_element(salary.begin(), salary.end());
        int sum = accumulate(salary.begin(), salary.end(), 0);
        return 1.0 * (sum - maxSalary - minSalary) / (salary.size()-2);
    }
};
// @lc code=end
/*
[4000,3000,1000,2000]\n
[1000,2000,3000]\n
[6000,5000,4000,3000,2000,1000]\n
[8000,9000,2000,3000,6000,1000]
*/
