/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
public:
    // 97 94;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructRecursively(nums, 0, nums.size()-1);
    }

    TreeNode* constructRecursively(vector<int>& nums, int begin, int end){
        if(begin < 0 || begin > end || end > nums.size()-1){
            return nullptr;
        }
        TreeNode* root = nullptr;
        int maxNum = nums[begin];
        int maxNumIndex = begin;
        for(int i = begin+1; i <= end; i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }
        root = new TreeNode(maxNum, nullptr, nullptr);
        root->left = constructRecursively(nums, begin, maxNumIndex - 1);
        root->right = constructRecursively(nums, maxNumIndex + 1, end);
        return root;
    }
};
// @lc code=end

