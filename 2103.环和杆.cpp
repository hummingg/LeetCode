/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    // 100 76; 100 32; 100 40;
    int countPoints(string rings) {
        vector<int> v(10, 0);
        for(int i = 0; i < rings.size()-1; i += 2){
            char no = rings[i+1] - '0';
            if(v[no] == 0b111){ // 自动将 char 转为 int ？
                continue;
            }
            char color = rings[i];
            switch (color)
            {
                case 'R':
                    v[no] |= 0b100;
                    break;
                case 'G':
                    v[no] |= 0b010;
                    break;
                case 'B':
                    v[no] |= 0b001;
                    break;
                default:
                    break;
            }
        }
        int count = 0;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] == 0b111){
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end
/*
'"B0B6G0R6R0R6G9"\n
"B0R0G0R9R0B0G0"\n
"G4"'
*/
