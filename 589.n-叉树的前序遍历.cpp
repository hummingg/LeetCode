/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // 进阶迭代
    // 28 95; 94 69;
    vector<int> preorder(Node* root) {
        if(!root){
            return {};
        }
        vector<int> v;
        stack<Node*> stk;
        Node* cur = root;
        stk.push(cur);
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            v.push_back(cur->val);
            for(int i = cur->children.size()-1; i>=0; i--){
                stk.push(cur->children[i]);
            }
        }
        return v;
    }

    // 简单递归
    vector<int> preorder1(Node* root) {
        vector<int> v;
        if(!root){
            return {};
        }
        v.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++){
            vector<int> c = preorder(root->children[i]);
            v.insert(v.end(), c.begin(), c.end());
        }
        return v;
    }
};
// @lc code=end

