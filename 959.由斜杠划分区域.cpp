/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
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
    // 会有 x 的方格
    int regionsBySlashes(vector<string>& grid) {
        // cout << grid << endl;
        int size = grid.size();
        for(int i = 0; i < size; ++i){
            
        }
        return 0;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<string> v = {"/\\","\\/"};
    cout << s.regionsBySlashes(v) << endl;
    return 0;
}
/*
撇：
00 01,10 n-10,0n-1 
["\\/","  "]
*/