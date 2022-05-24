/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
    // 85 26;
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int size = image.size();
        for(int i = 0; i < size; ++i){
            int low = 0, high = size - 1;
            while(low < high){
                int tmp = image[i][low];
                image[i][low] = 1-image[i][high];
                image[i][high] = 1-tmp;
                ++low;
                --high;
            }
            if(low == high){
                image[i][high] = 1-image[i][high];
            }
        }
        return image;
    }
};
// @lc code=end

