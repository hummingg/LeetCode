/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 进阶方法 100 56;
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int count = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(board[row][col] == '.'){
                    continue;
                }
                // 上一个和左一个为空则新增
                if((row-1<0 || board[row-1][col] == '.')
                    && (col-1<0 || board[row][col-1] == '.')){
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

