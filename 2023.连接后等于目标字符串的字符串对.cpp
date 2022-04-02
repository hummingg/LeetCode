/*
 * @lc app=leetcode.cn id=2023 lang=cpp
 *
 * [2023] 连接后等于目标字符串的字符串对
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
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
    // 67 62;
    int numOfPairs(vector<string>& nums, string target) {
        map<string, string> mss;
        map<string, int> msi;
        int size = target.size();
        for(int i = 0; i < size-1; ++i){
            mss.insert(make_pair(target.substr(0, i+1), target.substr(i+1)));
        }
        for(int i = 0; i < nums.size(); ++i){
            if(target.find_first_of(nums[i]) != string::npos)   // 优化不大
                msi[nums[i]]++; // 默认为0，然后++
            // cout << nums[i] << " " << msi[nums[i]] << endl;
        }
        int count = 0;
        for(auto ss : mss){
            if(ss.first == ss.second){
                count += msi[ss.first] * (msi[ss.second] - 1);
            }else{
                count += msi[ss.first] * msi[ss.second];
            }
        }
        return count;
    }
};
// @lc code=end
/*
["777","7","77","77"]\n"7777"
["123","4","12","34"]\n"1234"
["1","1","1"]\n"11"
*/
