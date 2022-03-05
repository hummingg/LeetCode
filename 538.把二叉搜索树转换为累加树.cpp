/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
private:
    int rightSum = 0;   // ≥当前结点值 的结点值之和
public:
    // 59 72;
    TreeNode* convertBST(TreeNode* root) {
        inverseMidOrder(root);
        return root;
    }
    
    // 逆中序遍历
    void inverseMidOrder(TreeNode* root){
        if(!root){
            return;
        }
        inverseMidOrder(root->right);
        rightSum += root->val;
        root->val = rightSum;
        // cout << rightSum << endl;
        inverseMidOrder(root->left);
    }
};
// @lc code=end

