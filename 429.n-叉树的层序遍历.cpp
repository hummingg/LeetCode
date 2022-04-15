/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    // 每组子节点都由 null 值分隔
    // 32 5;32 5;97 5;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            // return {{}}; // 错误
            return {};
        }
        vector<vector<int>> ret;
        queue<Node*> que;
        Node* cur;
        que.push(root);
        while(true){
            vector<int> v;
            queue<Node*> queNew;
            while(!que.empty()){
                cur = que.front();
                que.pop();
                v.push_back(cur->val);
                for(int i = 0; i<cur->children.size(); ++i){
                    queNew.push(cur->children[i]);
                }
            }
            ret.push_back(v);
            if(queNew.empty()){
                break;
            }
            que = queNew;
        }
        return ret;
    }
};
// @lc code=end
/*
[1,null,3,2,4,null,5,6]
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
*/
