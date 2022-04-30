/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    // 100 14;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        for(; k >= 0 && i >= 0 && j >= 0; --k){
            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];
                --i;
            }else{
                nums1[k] = nums2[j];
                --j;
            }
        }
        // i >= 0 不需要处理，已就位
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, count = 0;
        // cout << nums1.size() << endl;   // 已经填充了0
        nums1.resize(m);
        while(j < n){
            if(count < m && nums1[i] <= nums2[j]){
                ++i;++count;
            }else{
                nums1.insert(nums1.begin()+i, nums2[j]);    // O(n/2)
                ++i;++j;
            }
        }
        // for(int i = 0; i < nums1.size(); ++i){
        //     cout << nums1[i] << endl;
        // }
    }
};
// @lc code=end
/*
[1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
[1]\n1\n[]\n0\n
[0]\n0\n[1]\n1
*/
