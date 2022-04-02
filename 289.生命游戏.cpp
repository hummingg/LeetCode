/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    // 进阶的原地没想到
    // 100 12;
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> ret(rows, vector<int>(cols, 0));
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int count = 0;
                if(row-1 > -1 && col-1 > -1){
                    count += board[row-1][col-1];
                }
                if(row-1 > -1){
                    count += board[row-1][col];
                }
                if(row-1 > -1 && col+1 < cols){
                    count += board[row-1][col+1];
                }

                if(col-1 > -1){
                    count += board[row][col-1];
                }
                if(col+1 < cols){
                    count += board[row][col+1];
                }

                if(row+1 < rows && col-1 > -1){
                    count += board[row+1][col-1];
                }
                if(row+1 < rows){
                    count += board[row+1][col];
                }
                if(row+1 < rows && col+1 < cols){
                    count += board[row+1][col+1];
                }
                if(board[row][col] == 1 && count >= 2 && count <= 3 || board[row][col] == 0 && count == 3){
                    ret[row][col] = 1;
                }
            }
        }
        board = ret;
    }
    
    // 100 88;
    void gameOfLife1(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        if(rows == 1 && cols == 1){
            board = {{0}};
            return;
        }
        vector<vector<int>> ret(rows, vector<int>(cols, 0));
        if(rows == 1){
            for(int col = 1; col < cols - 1; col++){
                if(board[0][col] == 1 && board[0][col-1] + board[0][col+1] == 2){
                    ret[0][col] = 1;
                }
            }
            board = ret;
            return;
        }
        if(cols == 1){
            for(int row = 1; row < rows - 1; row++){
                if(board[row][0] == 1 && board[row-1][0] + board[row+1][0] == 2){
                    ret[row][0] = 1;
                }
            }
            board = ret;
            return;
        }
        int count = board[0][1] + board[1][0] + board[1][1];    // 左上
        if(board[0][0] == 1 && count > 1 || board[0][0] == 0 && count == 3){
            ret[0][0] = 1;
        }
        count = board[0][cols-2] + board[1][cols-2] + board[1][cols-1]; // 右上
        if(board[0][cols-1] == 1 && count > 1 || board[0][cols-1] == 0 && count == 3){
            ret[0][cols-1] = 1;
        }
        count = board[rows-2][0] + board[rows-2][1] + board[rows-1][1];    // 左下
        if(board[rows-1][0] == 1 && count > 1 || board[rows-1][0] == 0 && count == 3){
            ret[rows-1][0] = 1;
        }
        count = board[rows-1][cols-2] + board[rows-2][cols-2] + board[rows-2][cols-1];    // 右下
        if(board[rows-1][cols-1]== 1 && count > 1 || board[rows-1][cols-1] == 0 && count == 3){
            ret[rows-1][cols-1] = 1;
        }
        // cout << "111" << endl;
        for(int col = 1; col < cols-1; col++){  // 上横
            count = board[0][col-1] + board[1][col-1] + board[1][col] + board[1][col+1] + board[0][col+1];
            if(board[0][col] == 1 && count >= 2 && count <= 3 || board[0][col] == 0 && count == 3){
                ret[0][col] = 1;
            }
        }
        for(int col = 1; col < cols-1; col++){  // 下横
            count = board[rows-1][col-1] + board[rows-2][col-1] + board[rows-2][col] + board[rows-2][col+1] + board[rows-1][col+1];
            if(board[rows-1][col] == 1 && count >= 2 && count <= 3 || board[rows-1][col] == 0 && count == 3){
                ret[rows-1][col] = 1;
            }
        }
        for(int row = 1; row < rows-1; row++){  // 左竖
            int col = 0;
            count = board[row-1][col] + board[row-1][col+1] + board[row][col+1] + board[row+1][col+1] + board[row+1][col];
            if(board[row][col] == 1 && count >= 2 && count <= 3 || board[row][col] == 0 && count == 3){
                ret[row][col] = 1;
            }
        }
        // cout << "222" << endl;
        for(int row = 1; row < rows-1; row++){  // 右竖
            int col = cols-1;
            count = board[row-1][col] + board[row-1][col-1] + board[row][col-1] + board[row+1][col-1] + board[row+1][col];
            if(board[row][col] == 1 && count >= 2 && count <= 3 || board[row][col] == 0 && count == 3){
                ret[row][col] = 1;
            }
        }
        // cout << "333" << endl;
        for(int row = 1; row < rows-1; row++){
            for(int col = 1; col < cols-1; col++){
                count = board[row-1][col-1] + board[row-1][col] + board[row-1][col+1]
                    + board[row][col-1] + board[row][col+1]
                    + board[row+1][col-1] + board[row+1][col] + board[row+1][col+1];
                if(board[row][col] == 1 && count >= 2 && count <= 3 || board[row][col] == 0 && count == 3){
                    ret[row][col] = 1;
                }
            }
        }
        board = ret;
    }
};
// @lc code=end

