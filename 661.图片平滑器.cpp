/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
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
    // 30 92;
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size(), cols = img[0].size();
        vector<vector<int>> ret(rows, vector<int>(cols));
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int sum = img[row][col], count = 1;
                if(row-1 > -1 && col-1 > -1){
                    sum += img[row-1][col-1];
                    ++count;
                }
                if(row-1 > -1){
                    sum += img[row-1][col];
                    ++count;
                }
                if(row-1 > -1 && col+1 < cols){
                    sum += img[row-1][col+1];
                    ++count;
                }

                if(col-1 > -1){
                    sum += img[row][col-1];
                    ++count;
                }
                // sum += img[row][col];
                // ++count;
                if(col+1 < cols){
                    sum += img[row][col+1];
                    ++count;
                }

                if(row+1 < rows && col-1 > -1){
                    sum += img[row+1][col-1];
                    ++count;
                }
                if(row+1 < rows){
                    sum += img[row+1][col];
                    ++count;
                }
                if(row+1 < rows && col+1 < cols){
                    sum += img[row+1][col+1];
                    ++count;
                }
                ret[row][col] = sum / count;
            }
        }
        return ret;
    }
};
// @lc code=end
/*
{{1,1,1},{1,0,1},{1,1,1}}
{{100,200,100},{200,50,200},{100,200,100}}
*/
