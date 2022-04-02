/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <iostream>
#include <vector>
#include <iterator>
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
class Solution {
public:
    // 100 63;
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int n = (size-1) / 2;   // 从内到外的旋转
        for(int i = 0; i <= n; ++i){    // 从外到内旋转 n+1 个墙
            int beginRow = i, endRow = size-1-beginRow;
            int gap = endRow - beginRow;
            for(int rowGap = 0; rowGap < gap; ++rowGap){  // 处理 gap 轮
                // 轮流4次替换，因为二维共4条边
                int dstRow = beginRow, dstCol = beginRow + rowGap;
                int colGap = gap - rowGap;
                int pre = matrix[dstRow][dstCol], tmp = 0;
                // cout << pre << endl;

                dstRow = dstRow + rowGap;
                dstCol = dstCol + colGap;
                tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
                pre = tmp;
                // cout << pre << endl;

                dstRow = dstRow + colGap;
                dstCol = dstCol - rowGap;
                tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
                pre = tmp;
                // cout << pre << endl;
                
                dstRow = dstRow - rowGap;
                dstCol = dstCol - colGap;
                tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
                pre = tmp;
                // cout << pre << endl;

                dstRow = dstRow - colGap;
                dstCol = dstCol + rowGap;
                // tmp = matrix[dstRow][dstCol];
                matrix[dstRow][dstCol] = pre;
            }
        }
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(v);
    // cout << s.rotate(v) << endl;
    return 0;
}
/*
[[1]]

*/
