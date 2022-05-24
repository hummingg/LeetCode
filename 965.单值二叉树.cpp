/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
 *
 * https://leetcode-cn.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (68.73%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    40.5K
 * Total Submissions: 58.9K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[2,2,2,5,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
 * 
 * 
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
    int val;
public:
    // 100 48;
    // 层次遍历 
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int val = root->val;
        while(!que.empty()){
            auto parent = que.front();
            que.pop();
            auto node = parent->left;
            if(node){
                if(node->val != val){
                    return false;
                }else{
                   que.push(node); 
                }
            }
            node = parent->right;
            if(node){
                if(node->val != val){
                    return false;
                }else{
                   que.push(node); 
                }
            }
        }
        return true;
    }

    // 100 99; 45 32; 100 10; 100 29;
    // 先序遍历
    bool isUnivalTree1(TreeNode* root) {
        val = root->val;
        return preOrder(root);
    }
    bool preOrder(TreeNode* root) {
        if(!root){
            return true;
        }
        if(root->val != val){
            return false;
        }
        return preOrder(root->left) && preOrder(root->right);
    }
};
// @lc code=end

