/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>    // max({})
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
    // 双端队列出队顺序有 2^n 种
    bool stoneGame(vector<int>& piles) {
        int size = piles.size();
        if(size == 2){
            return true;
        }
        if(size == 3){
            return piles[0] + piles[2] > piles[1];  // 对手有可能拿到的最大值
        }
        int sum = accumulate(piles.begin(), piles.end(), 0);    // 求和
        int n = size;
        int begin = 0, end = size - 1;
        int count = 0;
        while(n >= 4){
            if(piles[begin] + piles[end-1] >= piles[begin+1]+piles[end]){
                count += piles[begin];
                begin++;
            }else{
                count += piles[end];
                end--;
            }
            if(piles[begin] + piles[end-1] >= piles[begin+1]+piles[end]){
                begin++;
            }else{
                end--;
            }
            n -= 2;
            cout << count << endl;
        }
        if(n == 2){
            count += max(piles[begin], piles[end]);
        }else{
            if(piles[begin+1] >= piles[begin] + piles[end]){
                count += piles[begin] + piles[end];
            }else{
                count += max({piles[begin], piles[begin+1], piles[end]}) + min({piles[begin], piles[begin+1], piles[end]});
            }
        }
        cout << count << endl;
        return count > sum / 2;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {6,3,9,9,3,8,8,7};
    // cout << max({1,2,3}) << endl;
    cout << s.stoneGame(v) << endl;
    return 0;
}
/*
[6,3,9,9,3,8,8,7]
6 8 3 9
7 8 3 9

7 
*/
