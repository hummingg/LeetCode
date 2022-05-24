/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    TreeNode* root;
    int low;
    int high;
    int sum = 0;
public:
    // 99 51;
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->root = root;
        this->low = low;
        this->high = high;
        midOrder(root);
        return sum;
    }

    void midOrder(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            midOrder(root->left);
        }
        int val = root->val;
        if(val >= low && val <= high){
            sum += val;
        }
        if(val > high){
            return;
        }
        if(root->right){
            midOrder(root->right);
        }
    }
};
// @lc code=end
/*
[10,5,15,3,7,13,18,1,null,6]\n6\n10
*/
