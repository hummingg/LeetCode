/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.93%)
 * Likes:    1563
 * Dislikes: 0
 * Total Accepted:    722.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [0]
 * 输出: [0]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：你能尽量减少完成的操作次数吗？
 * 
 */
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
// @lc code=start
class Solution {
public:
    // 36 22;
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(), count = 0;
        for(int i = 0; i < size; ++i){
            count += nums[i] != 0;
        }
        // cout << count << endl;
        if(count == size){
            return;
        }

        int end = 0;
        for(int i = 0; i < size && end < count; ++i){
            if(nums[i] != 0){
                if(end != i){
                    nums[end] = nums[i];
                }
                // --count;
                ++end;
            }
        }
        // cout << nums << endl;
        for(int i = count; i < size; ++i){
            nums[i] = 0;
        }
        // cout << nums << endl;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {0,1,0,3,12};
    s.moveZeroes(v);
    // cout << s.moveZeroes(v) << endl;
    return 0;
}
