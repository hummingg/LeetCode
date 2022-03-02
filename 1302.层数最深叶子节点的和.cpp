/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */
#include <iostream>
#include <queue>
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
class Solution {
public:
    // 6 48; 
    // 层次遍历 队列
    int deepestLeavesSum(TreeNode* root) {
        if(!root){
            return 0;
        }

        queue<TreeNode*> q;   // push front pop
        int countPre = 0, count = 0;
        int sum = 0;

        q.push(root);
        countPre++;
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            if(countPre == 0){  // p是新层第一个
                sum = 0;
                countPre = count - 1;   // 上一层还有 count-1 个未出队
                count = 0;  // 新层开始统计个数
            }else{
                countPre--;
            }
            
            sum += p->val;

            if(p->left){
                q.push(p->left);
                count++;
            }
            if(p->right){
                q.push(p->right);
                count++;
            }
        }
        
        return sum;
    }
};
// @lc code=end

