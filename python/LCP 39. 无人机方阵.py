'''
执行用时：
308 ms
, 在所有 Python3 提交中击败了
14.50%
的用户
内存消耗：
17.6 MB
, 在所有 Python3 提交中击败了
15.26%
的用户
通过测试用例：
85 / 85
'''

class Solution:
    def minimumSwitchingTimes(self, source: List[List[int]], target: List[List[int]]) -> int:
        ds = {i: 0 for i in range(1, 10001)}
        dt = {i: 0 for i in range(1, 10001)}
        n, m = len(source), len(source[0])
        total = n * m
        for s in source:
            for c in s:
                ds[c] += 1
        for t in target:
            for c in t:
                dt[c] += 1
        same = sum([min(ds[i], dt[i]) for i in range(1, 10001)])
        return total - same
