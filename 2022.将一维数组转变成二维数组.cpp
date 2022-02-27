/*
 * @lc app=leetcode.cn id=2022 lang=cpp
 *
 * [2022] 将一维数组转变成二维数组
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 80 100; 89 99; 80 98;
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> result;
        if(size != m * n){
            return result;
        }
        
        // 节省空间
        result.resize(m);
        // result.resize(m, vector<int>(n));   // 31 67; 23 88; 43 71;88 94

        int i = 0;
        for(vector<int>::iterator it = original.begin(); it != original.end();){
            // vector<int> v;   // 31 20;
            // v.assign(it, it+n);
            // result[i++] = v;
            result[i++].assign(it, it+n);   // 56 78; 100 70; 100 80; 节省时间
            it += n;
        }
        
        return result;
    }

    // 56 100;
    vector<vector<int>> construct2DArray2(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> result;
        if(size != m * n){
            return result;
        }
        
        // 节省内存
        result.resize(m, vector<int>(n));
        // result.resize(m);
        // for (int i = 0; i < m; i++){
        //     result[i].resize(n);
        // }

        int i = 0;
        int row = 0;
        // 时间复杂度高
        while(i < size){
            int count = 0;
            while(count < n){
                result[row][count] = original[i];
                count++;
                i++;
            }
            row++;
        }
        
        return result;
    }

    // 7 12;
    vector<vector<int>> construct2DArray1(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> result;
        if(size != m * n){
            return result;
        }

        int i = 0;
        while(i < size){
            int count = 0;
            vector<int> v;
            while(count < n){   //  && i < size
                v.push_back(original[i]);
                count++;
                i++;
            }
            result.push_back(v);
        }
        
        return result;
    }
};

// int main(){
//     Solution s;
//     vector<int> original {1,2,3,4,5,6};
//     int m = 3, n = 2;
    
//     // for(int i = 0; i < original.size(); i++){
//     //     cout << &original[i] << endl;
//     //     cout << original[i] << endl;
//     // }
//     // return 0;

//     vector<vector<int>> vv = s.construct2DArray(original, m, n);
//     for(vector<vector<int>>::iterator it1 = vv.begin(); it1 != vv.end(); it1++){
//         cout << "新元素" << endl;
//         for(vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++){
//             cout << (*it2) << endl;
//         }
//     }
    
//     return 0;
// }
// @lc code=end

