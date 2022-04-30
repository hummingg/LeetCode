/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 *
 * https://leetcode-cn.com/problems/construct-quad-tree/description/
 *
 * algorithms
 * Medium (62.12%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 10.1K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 。
 * 
 * 你需要返回能表示矩阵的 四叉树 的根结点。
 * 
 * 注意，当 isLeaf 为 False 时，你可以把 True 或者 False 赋值给节点，两种值都会被判题机制 接受 。
 * 
 * 四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：
 * 
 * 
 * val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False；
 * isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
 * 
 * 
 * class Node {
 * ⁠   public boolean val;
 * public boolean isLeaf;
 * public Node topLeft;
 * public Node topRight;
 * public Node bottomLeft;
 * public Node bottomRight;
 * }
 * 
 * 我们可以按以下步骤为二维区域构建四叉树：
 * 
 * 
 * 如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null
 * 然后停止。
 * 如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
 * 使用适当的子网格递归每个子节点。
 * 
 * 
 * 
 * 
 * 如果你想了解更多关于四叉树的内容，可以参考 wiki 。
 * 
 * 四叉树格式：
 * 
 * 输出为使用层序遍历后四叉树的序列化形式，其中 null 表示路径终止符，其下面不存在节点。
 * 
 * 它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 [isLeaf, val] 。
 * 
 * 如果 isLeaf 或者 val 的值为 True ，则表示它在列表 [isLeaf, val] 中的值为 1 ；如果 isLeaf 或者 val
 * 的值为 False ，则表示值为 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：grid = [[0,1],[1,0]]
 * 输出：[[0,1],[1,0],[1,1],[1,1],[1,0]]
 * 解释：此示例的解释如下：
 * 请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：grid =
 * [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
 * 
 * 输出：[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
 * 解释：网格中的所有值都不相同。我们将网格划分为四个子网格。
 * topLeft，bottomLeft 和 bottomRight 均具有相同的值。
 * topRight 具有不同的值，因此我们将其再分为 4 个子网格，这样每个子网格都具有相同的值。
 * 解释如下图所示：
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1],[1,1]]
 * 输出：[[1,1]]
 * 
 * 
 * 示例 4：
 * 
 * 输入：grid = [[0]]
 * 输出：[[1,0]]
 * 
 * 
 * 示例 5：
 * 
 * 输入：grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
 * 输出：[[0,1],[1,1],[1,0],[1,0],[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length == grid[i].length
 * n == 2^x 其中 0 <= x <= 6
 * 
 * 
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    vector<vector<int>> grid;   // 82 42; 98 40; 100 40;
public:
    // 5 6;
    Node* construct(vector<vector<int>>& grid) {
        int size = grid.size();
        if(!size){
            return nullptr;
        }
        this->grid = grid;
        return recurConstruct(0, 0, size-1, size-1);
    }

    Node* recurConstruct(int beginRow, int beginCol, int endRow, int endCol){
        // 值相同
        if(beginRow == endRow){
            return new Node(grid[beginRow][beginCol], 1);   // 是叶子
        }
        // beginRow, beginRow + (endRow-beginRow)/2, beginRow + (endRow-beginRow)/2+1, endRow
        // beginCol, beginCol + (endCol-beginCol)/2, beginCol + (endCol-beginCol)/2+1, endCol
        int midRow = (endRow+beginRow)/2, midCol = (endCol+beginCol)/2;
        int val0, val1, val2, val3;
        val0 = getVal(beginRow, beginCol, midRow, midCol);
        val1 = getVal(beginRow, midCol+1, midRow, endCol);
        val2 = getVal(midRow+1, beginCol, endRow, midCol);
        val3 = getVal(midRow+1, midCol+1, endRow, endCol);
        // cout << val0 << " " << val1 << " " << val2 << " " << val3 << endl;
        if(val0 != -1 && val0 == val1 && val0 == val2 && val0 == val3){
            return new Node(val0, 1);
        }

        // 值不同
        Node* root = new Node(1, 0);    // val 无所谓
        if(val0 == -1){
            root->topLeft = recurConstruct(beginRow, beginCol, midRow, midCol);
        }else{
            root->topLeft = new Node(val0, 1);
        }
        if(val1 == -1){
            root->topRight = recurConstruct(beginRow, midCol+1, midRow, endCol);
        }else{
            root->topRight = new Node(val1, 1);
        }
        if(val2 == -1){
            root->bottomLeft = recurConstruct(midRow+1, beginCol, endRow, midCol);
        }else{
            root->bottomLeft = new Node(val2, 1);
        }
        if(val3 == -1){
            root->bottomRight = recurConstruct(midRow+1, midCol+1, endRow, endCol);
        }else{
            root->bottomRight = new Node(val3, 1);
        }
        return root;
    }

    // 不同就返回-1，相同就返回值0或1
    int getVal(int beginRow, int beginCol, int endRow, int endCol){
        bool same = true;
        int firstVal = grid[beginRow][beginCol];
        // cout << beginRow << " " << beginCol << " " << endRow << " " << endCol << " " << firstVal << endl;
        for(int i = beginRow; i <= endRow && same; ++i){
            for(int j = beginCol; j <= endCol; ++j){
                if(grid[i][j] != firstVal){
                    same = false;
                    break;
                }
            }
        }
        if(same){
            return firstVal;
        }
        return -1;
    }
};
// @lc code=end
/*
[[0,1],[1,0]]\n
[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]\n
[[1,1],[1,1]]\n
[[0]]\n
[[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
*/
