/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 */
#include <iostream>
#include <vector>
#include <iterator>
// #include <>
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
private:
public:
    // 64 39;
    // 略low
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;
        vector<int> nums1;
        vector<int> nums2;
        midOrder(root1, nums1);
        midOrder(root2, nums2);
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ret.push_back(nums1[i++]);
            }else{
                ret.push_back(nums2[j++]);
            }
        }
        while(i < nums1.size()){
            ret.push_back(nums1[i++]);
        }
        while(j < nums2.size()){
            ret.push_back(nums2[j++]);
        }
        return ret;
    }

    void midOrder(TreeNode* root, vector<int>& nums){
        if(!root){
            return;
        }
        if(root->left){
            midOrder(root->left, nums);
        }
        nums.push_back(root->val);
        if(root->right){
            midOrder(root->right, nums);
        }
    }
};
// @lc code=end

