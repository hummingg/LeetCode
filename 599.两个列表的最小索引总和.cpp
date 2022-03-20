/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
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
    // 11 100; 23 95;
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> v;
        int minSumIndex = INT_MAX;
        for(int i = 0; i < list1.size() && i <= minSumIndex; i++){
            for(int j = 0; j < list2.size() && j <= minSumIndex; j++){
                if(list1[i] == list2[j]){
                    int sumIndex = i + j;
                    if(sumIndex == minSumIndex){
                        // cout << "add: " << list1[i] << endl;
                        v.push_back(list1[i]);
                    }else if(sumIndex < minSumIndex){
                        // cout << "清空: " << list1[i] << endl;
                        v.clear();
                        v.push_back(list1[i]);
                        minSumIndex = sumIndex;
                    }
                }
            }
        }
        return v;
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<int> v = {1, 2};
    //["Shogun", "Tapioca Express", "Burger King", "KFC"]\n["KFC", "Shogun", "Burger King"]
    vector<string> vs1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> vs2 = {"KFC", "Shogun", "Burger King"};
    cout << s.findRestaurant(vs1, vs2) << endl;
    return 0;
}
