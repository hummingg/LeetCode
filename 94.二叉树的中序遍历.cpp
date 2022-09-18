/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include "include/leetcode.h"
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
    // 100 92 0 8;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode*> stk;
        vector<int> ret;
        stk.push(root);
        TreeNode *p = root;
        while(p->left){
            stk.push(p->left);
            p = p->left;
        }
        while(!stk.empty()){
            p = stk.top();
            ret.push_back(p->val);
            stk.pop();
            if(!p->right){
                continue;
            }
            stk.push(p->right);
            p = p->right;
            while(p->left){
                stk.push(p->left);
                p = p->left;
            }
        }
        return ret;
    }
};
// @lc code=end
int main(){
    map<int,string> m;
    m[1] = "111";
    cout << m << endl;
    return 0;
}
