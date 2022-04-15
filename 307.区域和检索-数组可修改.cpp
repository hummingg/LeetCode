/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
private:
    vector<int> preSum;
    vector<int> nums;
    int size = 0;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->size = nums.size();
        preSum.resize(size);
        int sum = 0;
        for(int i = 0; i < size; ++i){
            sum += nums[i];
            preSum[i] = sum;
        }
    }
    
    // TLE
    void update(int index, int val) {
        int diff = val - nums[index];
        for(int i = index; i < size; ++i){
            preSum[i] += diff;
        }
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return preSum[right];
        }
        return preSum[right] - preSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

