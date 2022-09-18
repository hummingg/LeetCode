'''
剑指 Offer II 115. 重建序列
https://leetcode.cn/problems/ur2n8P/
给定一个长度为 n 的整数数组 nums ，其中 nums 是范围为 [1，n] 的整数的排列。还提供了一个 2D 整数数组 sequences ，其中 sequences[i] 是 nums 的子序列。
检查 nums 是否是唯一的最短 超序列 。最短 超序列 是 长度最短 的序列，并且所有序列 sequences[i] 都是它的子序列。对于给定的数组 sequences ，可能存在多个有效的 超序列 。

例如，对于 sequences = [[1,2],[1,3]] ，有两个最短的 超序列 ，[1,2,3] 和 [1,3,2] 。
而对于 sequences = [[1,2],[1,3],[1,2,3]] ，唯一可能的最短 超序列 是 [1,2,3] 。[1,2,3,4] 是可能的超序列，但不是最短的。
如果 nums 是序列的唯一最短 超序列 ，则返回 true ，否则返回 false 。
子序列 是一个可以通过从另一个序列中删除一些元素或不删除任何元素，而不改变其余元素的顺序的序列。

 

示例 1：

输入：nums = [1,2,3], sequences = [[1,2],[1,3]]
输出：false
解释：有两种可能的超序列：[1,2,3]和[1,3,2]。
序列 [1,2] 是[1,2,3]和[1,3,2]的子序列。
序列 [1,3] 是[1,2,3]和[1,3,2]的子序列。
因为 nums 不是唯一最短的超序列，所以返回false。
示例 2：

输入：nums = [1,2,3], sequences = [[1,2]]
输出：false
解释：最短可能的超序列为 [1,2]。
序列 [1,2] 是它的子序列：[1,2]。
因为 nums 不是最短的超序列，所以返回false。
示例 3：

输入：nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
输出：true
解释：最短可能的超序列为[1,2,3]。
序列 [1,2] 是它的一个子序列：[1,2,3]。
序列 [1,3] 是它的一个子序列：[1,2,3]。
序列 [2,3] 是它的一个子序列：[1,2,3]。
因为 nums 是唯一最短的超序列，所以返回true。
 

提示：

n == nums.length
1 <= n <= 10^4
nums 是 [1, n] 范围内所有整数的排列
1 <= sequences.length <= 10^4
1 <= sequences[i].length <= 10^4
1 <= sum(sequences[i].length) <= 10^5
1 <= sequences[i][j] <= n
sequences 的所有数组都是 唯一 的
sequences[i] 是 nums 的一个子序列
 

注意：本题与主站 444 题（会员题）相同：https://leetcode-cn.com/problems/sequence-reconstruction/

通过次数7,488提交次数20,292
'''

class Solution:
    # TLE
    def sequenceReconstruction(self, nums: List[int], sequences: List[List[int]]) -> bool:
        n = len(nums)
        grid = [[0 for _ in range(0, n+1)] for _ in range(0, n+1)]  # 深拷贝
        for seq in sequences:
            if len(seq) == 1:
                continue
            for i in range(0, len(seq)-1):
                grid[seq[i]][seq[i+1]] = 1
        # print(grid)
        # ret = []
        cnt = 0
        flags = [False] * (n+1)
        while True:
            start = 0
            for col in range(1, n+1):
                if not flags[col] and sum([grid[row][col] for row in range(1, n+1)]) == 0:
                    if start != 0:
                        return False
                    start = col
            if start == 0:
                return False
            flags[start] = True
            for col in range(1, n+1):
                grid[start][col] = 0
            # ret.append(start)
            cnt += 1
            # if len(ret) == n:
            if cnt == n:
                break
        # print(ret)
        return True
                
    def sequenceReconstruction9(self, nums: List[int], sequences: List[List[int]]) -> bool:
        dct = {}
        n = len(nums)
        for i in range(1, n+1):
            dct[i] = {'prev': set(), 'next': set()}
        # dct[1]["prev"].add(2)
        # print(dct)
        for seq in sequences:
            if len(seq) == 1:
                continue
            for i, num in enumerate(seq):
                if i == 0:
                    dct[num]['next'] = dct[num]['next'] - dct[seq[i+1]]['next']
                    dct[seq[i+1]]['prev'] = dct[seq[i+1]]['prev'] - dct[num]['prev']
                    dct[num]['next'].add(seq[i+1])
                    dct[seq[i+1]]['prev'].add(num)
                elif i == len(seq) - 1:
                    dct[num]['prev'] = dct[num]['prev'] - dct[seq[i-1]]['prev']
                    dct[seq[i-1]]['next'] = dct[seq[i-1]]['next'] - dct[num]['next']
                    dct[num]['prev'].add(seq[i-1])
                    dct[seq[i-1]]['next'].add(num)
                else:
                    dct[num]['next'] = dct[num]['next'] - dct[seq[i+1]]['next']
                    dct[seq[i+1]]['prev'] = dct[seq[i+1]]['prev'] - dct[num]['prev']
                    dct[num]['next'].add(seq[i+1])
                    dct[seq[i+1]]['prev'].add(num)
                    
                    dct[num]['prev'] = dct[num]['prev'] - dct[seq[i-1]]['prev']
                    dct[seq[i-1]]['next'] = dct[seq[i-1]]['next'] - dct[num]['next']
                    dct[num]['prev'].add(seq[i-1])
                    dct[seq[i-1]]['next'].add(num)
                    
        print(dct)
        