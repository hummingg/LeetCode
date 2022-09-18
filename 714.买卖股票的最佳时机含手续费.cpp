/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
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
    // wa 
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        if(size == 1){
            return 0;
        }else if(size == 2){
            return max(0, prices[1]- prices[0] -fee);
        }
        vector<int> waves;
        waves.push_back(prices[0]);
        int i = 1;
        // 递减后第一个变大的
        while(i < size && prices[i-1] >= prices[i]){
            i++;
        }
        if(i == size){  // 一减到底
            return 0;
        }
        if(i != 1){
            waves.push_back(prices[i-1]);   // 波谷
        }
        while(i < size){
            // 递增后第一个变小的
            while(i < size && prices[i-1] <= prices[i]){
                i++;
            }
            waves.push_back(prices[i-1]);   // 波峰
            if(i == size){
                break;
            }
            // 递减后第一个变大的
            while(i < size && prices[i-1] >= prices[i]){
                i++;
            }
            waves.push_back(prices[i-1]);   // 波谷
            if(i == size){
                break;
            }
        }
        // cout << waves << endl;
        i = 0;
        if(waves[0] > waves[1]){
            i = 1;  // 第一个低点
        }
        int prelow = waves[i], prehigh = waves[i+1];
        i += 2;
        int sum = 0;
        while(i+1 < waves.size()){
            int curlow = waves[i], curhigh = waves[i+1];
            if(curlow > prelow && curhigh > prehigh){
                if(prehigh - curlow > fee){ // 分成2次卖更赚
                    sum += max(0, prehigh - prelow - fee);
                    prelow = curlow;
                    prehigh = curhigh;
                }else{  // 坚持不卖
                    prehigh = curhigh;
                }
            }else{  // 卖
                sum += max(0, prehigh - prelow - fee);
                prelow = curlow;
                prehigh = curhigh;
            }
            i += 2;
        }
        sum += max(0, prehigh - prelow - fee);

        return sum;
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<int> v = {1, 3, 2, 8, 4, 9};
    // vector<int> v = {1, 3, 2, 8, 4, 9, 11};
    // vector<int> v = {1,3,7,5,10,3};
    vector<int> v = {1,3,7,5,10,3,1};
    int fee = 3;
    cout << s.maxProfit(v, fee) << endl;
    return 0;
}
/*
价 + >fee 才可能卖
[1, 3, 2, 7, 8, 4, 9], fee = 2 波峰波谷
 -1,0 -1,0 -1,    
dp[i,j]{}: 0<=i<j<=size-1之间的最小值和最大值

[1, 3, 2, 8, 4, 9]\n2
[1,3,7,5,10,3]\n3
[3,3,5,3,2,1,4,2,5,3]\n1
*/

