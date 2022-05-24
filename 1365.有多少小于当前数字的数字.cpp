/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
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
typedef pair<int, int> PAIR;
struct CmpByValue {    
    bool operator()(const PAIR& lhs, const PAIR& rhs) {    
        return lhs.second < rhs.second;    
    }
};
class Solution {
public:
    // 41 15;
    // 秀排序而已
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<PAIR> vp(size);
        for(int i = 0; i < size; i++){
            vp[i] = make_pair(i, nums[i]);  // first存了原索引但没用上
        }
        sort(vp.begin(), vp.end(), CmpByValue());
        vector<int> v(size);
        for(int i = 0; i < size; i++){
            int count = 0;
            int j = 0;
            while(j < size && vp[j].second < nums[i]){
                count++;
                j++;
            }
            v[i] = count;
        }
        return v;
    }

    // 34 63;
    vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
        vector<int> v;
        v.assign(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        vector<int> ret(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(v[j] < nums[i]){
                    ret[i]++;
                }else{
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

