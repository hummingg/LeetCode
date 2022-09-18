/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // 92 23 8 20.9;
private:
    vector<int> nums;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return sortedArrayToBST(0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(int low, int high) {
        if(low > high){
            return nullptr;
        }
        int mid = (low + high) / 2;
        TreeNode *left = sortedArrayToBST(low, mid-1);
        TreeNode *right = sortedArrayToBST(mid+1, high);
        return new TreeNode(nums[mid], left, right);
    }
};
// @lc code=end

