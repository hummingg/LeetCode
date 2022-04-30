/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
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
public:
    // 58 16;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        que.push(root);
        int count = 0;
        while(true){
            queue<TreeNode*> queNxt;
            vector<int> v;
            while(!que.empty()){
                TreeNode* node = que.front();
                if(count % 2 == 0){
                    v.push_back(node->val);
                }else{
                    v.insert(v.begin(), node->val); // 会慢？
                }
                que.pop();
                if(node->left){
                    queNxt.push(node->left);
                }
                if(node->right){
                    queNxt.push(node->right);
                }
            }
            ret.push_back(v);
            if(queNxt.empty()){
                break;
            }
            que = queNxt;
            ++count;
        }
        return ret;
    }
};
// @lc code=end

