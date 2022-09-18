class Solution:
    def volunteerDeployment(self, finalCnt: List[int], totalNum: int, edges: List[List[int]], plans: List[List[int]]) -> List[int]:
        n = len(finalCnt) + 1
        x = [0] * n   # x数组存放着x的系数，解方程用
        x[0] = 1    # 设finalCnt[0]=1*x+0，其他暂时为0
        finalCnt.insert(0, 0)
        neighbors = {i: set() for i in range(n)}
        for edge in edges:
            neighbors[edge[0]].add(edge[1])
            neighbors[edge[1]].add(edge[0])
        for i in range(len(plans)-1, -1, -1):
            num, idx = plans[i]
            if num == 1:
                finalCnt[idx] *= 2
                x[idx] *= 2
            elif num == 2:
                for neighbor in neighbors[idx]:
                    finalCnt[neighbor] -= finalCnt[idx]
                    x[neighbor] -= x[idx]
            else:
                for neighbor in neighbors[idx]:
                    finalCnt[neighbor] += finalCnt[idx]
                    x[neighbor] += x[idx]
        xx = (totalNum - sum(finalCnt)) // sum(x)
        ret = []
        for i in range(n):
            ret.append(finalCnt[i] + xx * x[i])
        return ret
'''
[1,16]
21
[[0,1],[1,2]]
[[2,1],[1,0],[3,0]]
[4,13,4,3,8]
54
[[0,3],[1,3],[4,3],[2,3],[2,5]]
[[1,1],[3,3],[2,5],[1,0]]
'''
