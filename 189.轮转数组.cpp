/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(k > size){
            k = k % size;
        }
        if(k == 0){
            return;
        }
        if(2 * k == size){  // n*k == size? k个环，每环n个
            // 0&k 1&k+1
            for(int i = 0; i < k;i++){
                int tmp = nums[i];
                nums[i] = nums[i+k];
                nums[i+k] = tmp;
            }
            return;
        }

        int index = 0;  // 从索引0开始层层压榨
        int tmpOld = nums[index];
        int finalIndex = 0;
        int tmpNew = 0;
        int count = 0;
        while(count < size){
            // 0->k k->2k 2k->3k
            finalIndex = (index+k) % size;
            tmpNew = nums[finalIndex];
            nums[finalIndex] = tmpOld;
            tmpOld = tmpNew;
            count++;
            
            index = finalIndex; // 2k = mn时死循环
        }
    }
};
// @lc code=end

