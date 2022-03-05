/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 */
#include <iostream>
#include <stack>
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
private:
    int rightSum = 0;   // ≥当前结点值 的结点值之和
public:
    // 同 538 题
    // 17 78;
    TreeNode* bstToGst(TreeNode* root) {
        // stack<TreeNode*> stk;
        // midOrder(root, stk);
        // ...

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

    // 中序遍历
    // void midOrder(TreeNode* root, stack<TreeNode*>& stk){
    //     if(!root){
    //         return;
    //     }
    //     if(root->left){
    //         midOrder(root->left, stk);
    //     }
    //     stk.push(root);
    //     if(root->right){
    //         midOrder(root->right, stk);
    //     }
    // }
};
// @lc code=end

