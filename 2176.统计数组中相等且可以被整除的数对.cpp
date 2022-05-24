/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
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
    // 83 6;
    int countPairs(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        int size = nums.size();
        int count = 0;
        for(int i = 0; i < size; ++i){
            m[nums[i]].push_back(i);
        }
        for(auto [_,v] : m){
            if(v.size() < 2){
                continue;
            }
            for(int i = 0; i < v.size()-1; ++i){
                for(int j = i+1; j < v.size(); ++j){
                    if(v[i] * v[j] % k == 0){
                        ++count;
                    }
                }
            }
        }
        return count;
    }

    // 100 24;
    int countPairs0(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size; ++j){
                if(nums[i] == nums[j] && i * j % k == 0){
                    ++count;
                }
            }
        }
        return count;
    }
    
    // 6 5;
    int countPairs1(vector<int>& nums, int k) {
        vector<vector<int>> vvi;
        for(int i = 0; i < nums.size(); ++i){
            vvi.push_back({nums[i], i});
        }
        sort(vvi.begin(), vvi.end());
        // for(auto v : vvi){
        //     cout << v << endl;
        // }
        int count = 0;
        for(int i = 0; i < vvi.size(); ++i){
            for(int j = i+1; j < vvi.size() && vvi[j][0] == vvi[i][0]; ++j){
                if(vvi[j][1]*vvi[i][1] % k == 0){
                    ++count;
                }
            }
        }
        return count;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {5,5,9,2,5,5,9,2,2,5,5,6,2,2,5,2,5,4,3};
    cout << s.countPairs1(v, 7) << endl;
    return 0;
}
