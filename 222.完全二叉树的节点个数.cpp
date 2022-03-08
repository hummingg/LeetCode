/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <iostream>
#include <stack>
#include <vector>
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
    int height = 0;
    // int countUp = 0;
    int count = 0;  // 底层结点数
    bool full = true;   // 是否满二叉树，默认是
public:
    // 25 70;
    // 进阶方法：计算层数，找到最后一个非双子的父结点
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        // 一路向左求层数
        TreeNode *p = root;
        while(p){
            height++;
            p = p->left;
        }
        preOrder(root, 1);
        if(!full){    // 不是满二叉树
            return pow(2, height-1) - 1 + count;
        }else{  // 是满二叉树
            return pow(2, height) - 1;
        }
    }

    // 先序遍历，满足先左后右，且方便计算层号
    void preOrder(TreeNode* root, int curHeight){
        if(!full || !root){ // 已经知道不是满二叉树了，可以直接计算了
            return;
        }
        if(curHeight == height){
            count++;
        }else if(curHeight == height - 1){
            // countUp++;
            if(!root->left){
                full = false;
                return; // 不调用preOrder了，剪枝
            }
            if(!root->right){
                count++;    // 手动加个底层左子结点，因为full会拦截对它的遍历
                full = false;
                return;
            }
        }
        preOrder(root->left, curHeight+1);
        preOrder(root->right, curHeight+1);
    }
};
// @lc code=end

