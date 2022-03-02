/*
 * @lc app=leetcode.cn id=1476 lang=cpp
 *
 * [1476] 子矩形查询
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start

class SubrectangleQueries {
private:
    vector<vector<int>> rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        // if(row1 > row2 || col1 > col2){
        //    return;
        // }
        for(int row = row1; row <= row2; row++){
            for(int col = col1; col <= col2; col++){
                rect[row][col] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end

