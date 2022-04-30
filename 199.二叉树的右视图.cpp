/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    // 100 5;
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ret;
        queue<TreeNode*> queLayer;
        queLayer.push(root);
        while(true){
            ret.push_back(queLayer.back()->val);
            queue<TreeNode*> queNextLayer;
            while(!queLayer.empty()){
                auto front = queLayer.front();
                queLayer.pop();
                if(front->left){
                    queNextLayer.push(front->left);
                }
                if(front->right){
                    queNextLayer.push(front->right);
                }
            }
            if(queNextLayer.empty()){
                break;
            }
            queLayer = queNextLayer;
        }
        return ret;
    }
};
// @lc code=end

