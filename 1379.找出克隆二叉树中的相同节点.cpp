/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

// @lc code=start
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // cout << target->val << endl;
        TreeNode* node = preOrder(cloned, target->val);
        // if(node){
        //     cout << node->val << endl;
        //     cout << node << endl;
        //     return node;
        // }
        return node ? node : nullptr;
    }

    TreeNode* preOrder(TreeNode *root, int target){
        if(root == nullptr){
            return nullptr;
        }
        // cout << root->val << endl;
        if(root->val == target ){
            return root;
        }

        TreeNode* node = nullptr;
        node = preOrder(root->left, target);
        if(node != nullptr){
            return node;
        }
        node = preOrder(root->right, target);
        return node;
    }
};
// @lc code=end

