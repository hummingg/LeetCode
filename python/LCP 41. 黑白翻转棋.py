class Solution:
    # 25.81%(152 ms) 22.58%(15.2 MB)
    def flipChess(self, chessboard: List[str]) -> int:
        chessboard = [list(row) for row in chessboard]
        n, m = len(chessboard), len(chessboard[0])
        origin = copy.deepcopy(chessboard)
        directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
        # origin[0][0] = 'X'
        # print(chessboard[0][0])
        que = []
        ret = 0
        for ii in range(n):
            for jj in range(m):
                if chessboard[ii][jj] != '.':
                    continue
                
                chessboard[ii][jj] = 'X'
                que.append((ii, jj))
                cnt = 0
                while len(que)>0:
                    row, col = que.pop(0)
                    tmpque = []
                    # print(row, col)
                    
                    for d in directions:
                        tmpq = []
                        i, j = row+d[0], col+d[1]
                        while i>=0 and i<n and j>=0 and j<m and chessboard[i][j] == 'O':
                            tmpq.append((i, j))
                            i += d[0]
                            j += d[1]
                        if i>=0 and i<n and j>=0 and j<m and chessboard[i][j] == 'X':
                            tmpque.extend(tmpq)
                        
                        
                    cnt += len(tmpque)
                    for r, c in tmpque:
                        # print(r,c)
                        chessboard[r][c] = 'X'
                    que.extend(tmpque)
                ret = max(ret, cnt)
                chessboard = copy.deepcopy(origin)
        return ret
    
class Solution9:
    def flipChess(self, chessboard: List[str]) -> int:
        chessboard = [list(row) for row in chessboard]
        n, m = len(chessboard), len(chessboard[0])
        origin = copy.deepcopy(chessboard)
        directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
        # origin[0][0] = 'X'
        # print(chessboard[0][0])
        que = []
        ret = 0
        for ii in range(n):
            for jj in range(m):
                if chessboard[ii][jj] != '.':
                    continue
                
                chessboard[ii][jj] = 'X'
                que.append((ii, jj))
                cnt = 0
                while len(que)>0:
                    row, col = que.pop(0)
                    tmpque = []
                    # print(row, col)
                    
                    for d in directions:
                        tmpq = []
                        i, j = row+d[0], col+d[1]
                        while i>=0 and i<n and j>=0 and j<m and chessboard[i][j] == 'O':
                            tmpq.append((i, j))
                            i += d[0]
                            j += d[1]
                        if i>=0 and i<n and j>=0 and j<m and chessboard[i][j] == 'X':
                            tmpque.extend(tmpq)
                    # 左
                    tmpq = []
                    j = col-1
                    while j >= 0 and chessboard[row][j] == 'O':
                        tmpq.append((row, j))
                        j -= 1
                    if j >= 0 and chessboard[row][j] == 'X':
                        tmpque.extend(tmpq)
                    # 右
                    tmpq = []
                    j = col+1
                    while j<m and chessboard[row][j] == 'O':
                        tmpq.append((row, j))
                        j += 1
                    if j<m and chessboard[row][j] == 'X':
                        tmpque.extend(tmpq)
                    # 上
                    tmpq = []
                    i = row-1
                    while i >= 0 and chessboard[i][col] == 'O':
                        tmpq.append((i, col))
                        i -= 1
                    if i >= 0 and chessboard[i][col] == 'X':
                        tmpque.extend(tmpq)
                    # 下
                    tmpq = []
                    i = row+1
                    while i<n and chessboard[i][col] == 'O':
                        tmpq.append((i, col))
                        i += 1
                    if i<n and chessboard[i][col] == 'X':
                        tmpque.extend(tmpq)
                    # 左上
                    tmpq = []
                    i = row-1
                    j = col-1
                    while i>= 0 and j >= 0 and chessboard[i][j] == 'O':
                        tmpq.append((i, j))
                        i -= 1
                        j -= 1
                    if i>= 0 and j >= 0 and chessboard[i][j] == 'X':
                        tmpque.extend(tmpq)
                    # 右下
                    tmpq = []
                    i = row+1
                    j = col+1
                    while i<n and j<m and chessboard[i][j] == 'O':
                        tmpq.append((i, j))
                        i += 1
                        j += 1
                    if i<n and j<m and chessboard[i][j] == 'X':
                        tmpque.extend(tmpq)
                    # 左下
                    tmpq = []
                    i = row+1
                    j = col-1
                    while i<n and j >= 0 and chessboard[i][j] == 'O':
                        tmpq.append((i, j))
                        i += 1
                        j -= 1
                    if i<n and j >= 0 and chessboard[i][j] == 'X':
                        tmpque.extend(tmpq)
                    # 右上
                    tmpq = []
                    i = row-1
                    j = col+1
                    while i>=0 and j<m and chessboard[i][j] == 'O':
                        tmpq.append((i, j))
                        i -= 1
                        j += 1
                    if i>=0 and j<m and chessboard[i][j] == 'X':
                        tmpque.extend(tmpq)
                        
                        
                        
                    cnt += len(tmpque)
                    for r, c in tmpque:
                        # print(r,c)
                        chessboard[r][c] = 'X'
                    que.extend(tmpque)
                ret = max(ret, cnt)
                chessboard = copy.deepcopy(origin)
        return ret