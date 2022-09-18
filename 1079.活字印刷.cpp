/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
class Solution {
public:
    int numTilePossibilities(string tiles) {
        // int nums[26]{};
        map<int, int> m;
        int size = tiles.size();
        for(int i = 0; i < size; ++i){
            int key = tiles[i]-'A';
            if(m.find(key) == m.end()){
                m[key] = 1;
            }else{
                ++m[key];
            }
            // ++nums[tiles[i]-'A'];
        }
        // for(int i = 0; i < 26; ++i){
        //     cout << nums[i] << endl;
        // }
        for(auto it=m.begin(); it!=m.end();++it){
            cout << it->first << " " << it->second << endl;
        }
        int count = m.size();
        for(int i = 2; i <= m.size(); ++i){ // 长度
            // todo
        }
        return count;
    }
};
// @lc code=end

