/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <iostream>
#include <vector>
#include <set>
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
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<vector<T>>& vv) {
    out << '[';
    for(int i = 0; i < vv.size(); i++){
        auto v = vv[i];
        if (!v.empty()) {
            out << '[';
            std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
            out << "], ";
        }
    }
    out << "]";
    return out;
}

// bool comp(const vector<int> &a,const vector<int> &b){
// 	return a[0] < b[0];
// }
// @lc code=start
class Solution {
public:
    // 99 43;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        vector<int> leftIndexes(size);
        for(int i = 0; i < size; i++){
            leftIndexes[i] = i;
        }
        sort(people.begin(), people.end());
        // sort(people.begin(), people.end(), comp);
        // cout << people << endl;
        vector<int> indexes(size);
        int preHigh = -1, preCount = 0;
        for(int i = 0; i < size; i++){
            vector<int> v = people[i];
            // cout << v[1] << " ";
            if(v[0] == preHigh){
                // preCount 修复 Runtime Error negative-size-param: (size=-4)
                indexes[i] = leftIndexes[v[1]-preCount]; // indexes[i-1] + v[1] - people[i-1][1]-1
                leftIndexes.erase(leftIndexes.begin() + v[1]-preCount);
                ++preCount;
            }else{
                indexes[i] = leftIndexes[v[1]];
                leftIndexes.erase(leftIndexes.begin() + v[1]);
                preHigh = v[0];
                preCount = 1;
            }
            // cout << indexes[i] << " " << leftIndexes << endl;
        }
        vector<vector<int>> vvi(size);
        for(int i = 0; i < size; i++){
            vvi[indexes[i]] = people[i];
        }
        return vvi;
    }
};
// @lc code=end
int main(){
    Solution s;
    // vector<vector<int>> v = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    // vector<vector<int>> v = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    vector<vector<int>> v = {{0,0},{6,2},{5,5},{4,3},{5,2},{1,1},{6,0},{6,3},{7,0},{5,1}};    
    cout << s.reconstructQueue(v) << endl;
    return 0;
}
/*
 * [[4, 4, ][5, 0, ][5, 2, ][6, 1, ][7, 0, ][7, 1, ]]
    4     ^4的0=0 ^04的2-1=2 ^024的1=3 ^0234的0=1 ^01234的1=5
    [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]

    [[0,0],[6,2],[5,5],[4,3],[5,2],[1,1],[6,0],[6,3],[7,0],[5,1]]
    [[0, 0, ], [1, 1, ], [4, 3, ], [5, 1, ], [5, 2, ], [5, 5, ], [6, 0, ], [6, 2, ], [6, 3, ], [7, 0, ], ]
 */