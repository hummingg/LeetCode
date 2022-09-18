```Python {}
class Solution:
    # 51 76 56 16; 89 64 44 16;
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        nums[0] < nums[1] > nums[2] < nums[3]...
        no '='
        """

        size = len(nums)
        if size == 1:
            return

        numscp = copy.copy(nums)
        numscp.sort()
        begin, end = 0, size - 1
        for i in range(size):
            if i % 2 == 0:
                nums[i] = numscp[begin]
                begin += 1
            else:
                nums[i] = numscp[end]
                end -= 1

        # 最后一串可能相等，插缝修改，确定初始交换的双方
        begin, end = size - 1, size - 1
        while nums[begin] == nums[end]:
            begin -= 1
        begin += 1
        if begin == end:
            return

        if (end - begin) % 2 == 0:
            begin += 1  # 最少的改变，最小的影响
        target = 0 if begin % 2 == 0 else 1 # 换首部小的(0)还是大的(1)

        while begin < size:
            # if nums[begin] != nums[target]:   // 思路不清晰，兜底打补丁才用
            nums[begin], nums[target] = nums[target], nums[begin]
            # else:
            #     nums[begin-1], nums[target-1] = nums[target-1], nums[begin-1]
            begin += 2
            target += 2
            
```
```Python {}
class Solution:
    # 51 76 56 16; 89 64 44 16;
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        nums[0] < nums[1] > nums[2] < nums[3]...
        no '='
        """

        size = len(nums)
        if size == 1:
            return

        numscp = copy.copy(nums)
        numscp.sort()
        begin, end = 0, size - 1
        for i in range(size):
            if i % 2 == 0:
                nums[i] = numscp[begin]
                begin += 1
            else:
                nums[i] = numscp[end]
                end -= 1

        # 最后一串可能相等，插缝修改，确定初始交换的双方
        begin, end = size - 1, size - 1
        while nums[begin] == nums[end]:
            begin -= 1
        begin += 1
        if begin == end:
            return

        if (end - begin) % 2 == 0:
            begin += 1  # 最少的改变，最小的影响
        target = 0 if begin % 2 == 0 else 1 # 换首部小的(0)还是大的(1)

        while begin < size:
            # if nums[begin] != nums[target]:   // 思路不清晰，兜底打补丁才用
            nums[begin], nums[target] = nums[target], nums[begin]
            # else:
            #     nums[begin-1], nums[target-1] = nums[target-1], nums[begin-1]
            begin += 2
            target += 2
            
```

