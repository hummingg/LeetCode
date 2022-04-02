/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    vector<int> v;
public:
    // 50 92;
    bool findTarget(TreeNode* root, int k) {
        midOrder(root);
        int low = 0, high = v.size()-1;
        while(low < high){
            int sum = v[low] + v[high];
            if(sum > k){
                high--;
            }else if(sum == k){
                return true;
            }else{
                low++;
            }
        }
        return false;
    }

    void midOrder(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            midOrder(root->left);
        }
        v.push_back(root->val);
        if(root->right){
            midOrder(root->right);
        }
    }
};
// @lc code=end
// [5,3,6,2,4,null,7]\n28
// [1]\n1
// [2,1,null]\n3
// [1]\n2
