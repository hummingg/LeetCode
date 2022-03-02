/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
public:
    int sumEvenGrandparent(TreeNode* root) {
        return preOrder(root);
    }

    int preOrder(TreeNode* root){
        if(!root){
            return 0;
        }

        int sum = 0;
        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left){
                    sum += root->left->left->val;
                }
                if(root->left->right){
                    sum += root->left->right->val;
                }
            }
            if(root->right){
                if(root->right->left){
                    sum += root->right->left->val;
                }
                if(root->right->right){
                    sum += root->right->right->val;
                }
            }
        }

        sum += preOrder(root->left);
        sum += preOrder(root->right);

        return sum;
    }
};
// @lc code=end

