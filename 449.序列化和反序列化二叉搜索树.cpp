/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (56.58%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 38.5K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 * 
 * 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 * 
 * 编码的字符串应尽可能紧凑。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [2,1,3]
 * 输出：[2,1,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数范围是 [0, 10^4]
 * 0 <= Node.val <= 10^4
 * 题目数据 保证 输入的树是一棵二叉搜索树。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // 63 93;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        if(!root){
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                ret += to_string(node->val) + "#";
                q.push(node->left);
                q.push(node->right);
            }else{
                ret += "#";
            }
        }
        // cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        queue<TreeNode*> q;
        string strval;
        int i = 0, j = data.find('#', i);
        strval = data.substr(i, j-i);
        // p->val = atoi(data.substr(i, j));
        TreeNode* root = new TreeNode(stoi(strval));
        q.push(root);
        i = j+1;
        TreeNode* p;
        while(i < data.size()){
            p = q.front();
            q.pop();
            j = data.find('#', i);
            strval = data.substr(i, j-i);
            // cout << j << endl;
            // cout << strval << endl;
            if(strval == ""){
                p->left = nullptr;
            }else{
                p->left = new TreeNode(stoi(strval));
                q.push(p->left);
            }
            i = j+1;
            
            j = data.find('#', i);
            strval = data.substr(i, j-i);
            // cout << j << endl;
            // cout << strval << endl;
            if(strval == ""){
                p->right = nullptr;
            }else{
                p->right = new TreeNode(stoi(strval));
                q.push(p->right);
            }
            i = j+1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end