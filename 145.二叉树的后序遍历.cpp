/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <iostream>
#include <vector>
#include <iterator>
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
    // 40 5 4 9.3;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        auto v = postorderTraversal(root->left);
        auto right = postorderTraversal(root->right);
        v.insert(v.end(), right.begin(), right.end());
        v.push_back(root->val);
        return v;
    }

    // Wrong 
    vector<int> postorderTraversal9(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode*> stk;
        stack<TreeNode*> stkRightVisited;
        vector<int> ret;
        stk.push(root);
        TreeNode* p = root;
        while(p->left){
            stk.push(p->left);
            p = p->left;
        }
        while(!stk.empty()){
            p = stk.top();
            if(!p->right){
                ret.push_back(p->val);
                stk.pop();
                continue;
            }
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

