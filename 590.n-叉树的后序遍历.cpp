/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}

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
    // 95 67;
    vector<int> postorder(Node* root) {
        vector<int> v;
        stack<Node*> stk;
        stack<Node*> path;
        if(!root){
            return v;
        }
        stk.push(root);
        path.push(nullptr);
        while(!stk.empty()){
            Node* p = stk.top();
            if(p->children.size() == 0){
                v.push_back(p->val);
                stk.pop();
            }else if(p!=path.top()){    // 不是上一个父节点
                path.push(p);
                for(int i = p->children.size() - 1; i >= 0; i--){
                    stk.push(p->children[i]);
                }
            }else{
                v.push_back(p->val);
                stk.pop();

                path.pop();
            }
        }
        return v;
    }

    // 27 11;
    vector<int> postorder1(Node* root) {
        vector<int> v;
        vector<int> vtmp;
        if(!root){
            return v;
        }
        for(auto child : root->children){
            vtmp = postorder(child);
            v.insert(v.end(), vtmp.begin(), vtmp.end());
        }
        v.push_back(root->val);
        return v;
    }
};
// @lc code=end

