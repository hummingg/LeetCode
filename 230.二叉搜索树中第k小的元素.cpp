/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
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
private:
    int count = 0;
    int kth = 0;
    int ret = 0;
public:
    // 进阶：二叉中序线索树

    // 普通递归 71 78;
    int kthSmallest(TreeNode* root, int k) {
        kth = k;
        midOrder(root);
        return ret;
    }

    void midOrder(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            midOrder(root->left);
        }
        count++;
        if(count == kth){
            ret = root->val;
            return;
        }
        if(root->right){
            midOrder(root->right);
        }
    }
};
// @lc code=end

