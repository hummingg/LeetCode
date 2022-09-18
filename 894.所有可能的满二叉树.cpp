/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 */
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
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
    int nodeNumber;
    int usedNode = 0;
    int flagSize = 0;
    vector<bool> flags;
    vector<TreeNode*> trees;
    set<int> leaves;
    vector<vector<int>> vv;
public:
    // 通过率高可能是因为测试用例已知且数量为个数
    // 和国内教材的满二叉树定义不一样
    // 利用完全二叉树的性质，2i 2i+1
    // 最多n/2+1 层，完全满二叉有pow(2, n/2+1)-1个结点
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0){
            return {};
        }
        if(n == 1){
            TreeNode* root = new TreeNode();
            return {root};
        }
        
        // TreeNode* left = new TreeNode();
        // TreeNode* right = new TreeNode();
        // TreeNode* root = new TreeNode(0, left, right);
        // allPossibleFBT(n-3);

        nodeNumber = n;
        flagSize = pow(2, n/2+1);
        flags.assign(flagSize, false); // 索引0用来占位
        flags[1] = true;
        usedNode += 1;
        TreeNode* root = new TreeNode();
        // allPossibleFBT(n);
        leaves.insert(1);
        recursion(1, n-1);  // 以结点1为根节点，生成2棵满二叉子树
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        cout << vv.size() << endl;

        for(auto v : vv){
            trees.push_back(buildTree(1, v));
            for(auto i : v){
                cout << i << " ";
            }
            cout << endl;
        }
        return trees;
    }
    
    void recursion(int root, int n){
        // cout << root << endl;
        if(n == 0){
            // trees.push_back(buildTree());
            if(usedNode != nodeNumber){
                return;
            }
            vector<int> v;
            int count = 0;
            for(int i = 0; i < flagSize && count < nodeNumber; i++){
                v.push_back(flags[i]);
                if(flags[i]){
                    count++;
                }
                // cout << it << " ";
            }
            vv.push_back(v);
            // cout << endl;
            return;
        }
        int base = 2 * root;
        flags[base]  = true;
        flags[base + 1] = true;
        usedNode += 2;
        
        bool tmp[flagSize];
        for(int i = 0; i < flagSize; i++){
            tmp[i] = flags[i];
        }
        int tmpUsedNode = usedNode;
        // leaves.erase(root);
        // leaves.insert(base);
        // leaves.insert(base+1);

        // n-2 个怎么 分配偶数个 给所有叶节点 并 去重
        // 19个结点
        // 18 = 0+18 = (2+16) = ... = 16+2 = 18+0
        // 2 = 0+2 = 2+0
        // 16 = 0+16 = 2+14 = ... = 16+0
        // recursion(base, n-2);
        // recursion(base+1, n-2);

        // 9开始有bug
        for(int i = 0; i <= (n-2) / 2; i++){
            recursion(base, 2 * i); // 内部又回退了，没有保存到。
            recursion(base+1, n -2 - 2 * i);
            // 回退
            for(int i = 0; i < flagSize; i++){
                flags[i] = tmp[i];
            }
            usedNode = tmpUsedNode;
        }
        // for(auto leaf : leaves ){
        //     recursion(leaf, n-2);
        //     cout << leaf << " ";
        // }
        // cout << endl;
        // flags[base]  = false;   // 回退了
        // flags[base + 1] = false;
        // usedNode -= 2;
        // leaves.insert(root);
        // leaves.erase(base);
        // leaves.erase(base+1);
    }

    TreeNode* buildTree(int rootNumber, const vector<int>& v){
        if(rootNumber > v.size()-1 || !v[rootNumber]){
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        int childBase = 2 * rootNumber;
        root->left = buildTree(childBase, v);
        root->right = buildTree(childBase+1, v);
        return root;
    }
};

// int main()
// {
//     Solution s;
//     // vector<string> v = {"1", "2"};
//     vector<vector<int>> vv;
//     vector<int> v1 = {1, 2};
//     vector<int> v2;
//     v2.push_back(1);
//     v2.push_back(2);
//     vv.push_back(v1);
//     vv.push_back(v2);
//     // vv.erase(unique(vv.begin(), vv.end()), vv.end());
//     // cout << (v1==v2) << endl;   // true
//     // vector<bool> v = {false};
//     // cout << vv.size() << endl;
//     s.allPossibleFBT(19);
//     // cout << s.allPossibleFBT(2) << endl;
//     return 0;
//     // 0 1 1 1 0 0 1 1 0 0 0 0 0 0 1 1
//     // 0 1 1 1 0 0 1 1 0 0 0 0 1 1 0 0
//     // 0 1 1 1 1 1 0 0 0 0 1 1 0 0 0 0
//     // 0 1 1 1 1 1 0 0 1 1 0 0 0 0 0 0
// }
// @lc code=end

