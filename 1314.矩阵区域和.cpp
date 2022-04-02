/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
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
    // 9 93;fmax效果 12 94;
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> v(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                int fmax = min(m-1, i+k);
                for(int f = max(0,i-k); f <= fmax; f++){
                    int gmax = min(n-1, j+k);
                    for(int g = max(0,j-k); g <= gmax; g++){
                        sum += mat[f][g];
                    }
                }
                v[i][j] = sum;
            }
        }
        return v;
    }
};
// @lc code=end

