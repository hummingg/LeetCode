/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
public:
    // 5 5;
    string tree2str(TreeNode* root) {
        string ret = "";
        if(!root){
            return ret;
        }
        ret += to_string(root->val);
        string left = "";
        if(root->left){
            left = tree2str(root->left);
        }
        string right = "";
        if(root->right){
            right = tree2str(root->right);
        }
        if(root->left){
            if(root->right){
                ret += "(" + left + ")(" + right + ")";
            }else{
                ret += "(" + left + ")";
            }
        }else{
            if(root->right){
                ret += "()(" + right + ")";
            }
        }
        return ret;
    }
};
// @lc code=end

