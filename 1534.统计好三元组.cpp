/*
 * @lc app=leetcode.cn id=1534 lang=cpp
 *
 * [1534] 统计好三元组
 */

// @lc code=start
class Solution {
    // 76 83 36 7.9;
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int size = arr.size();
        for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size; ++j){
                for(int k = j+1; k < size; ++k){
                    if(abs(arr[i]-arr[j])<= a&&abs(arr[i]-arr[k])<= c&&abs(arr[j]-arr[k])<= b){
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

/*
[1,1,2,2,3]\n0\n0\n1
*/