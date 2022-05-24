/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    // 64 81;
    string destCity(vector<vector<string>>& paths) {
        // 注意起点也只有一个
        set<string> st;
        int size = paths.size();
        // 处理到达站
        for(int i = 0; i < size; ++i){
            auto it = st.find(paths[i][1]); // 收集目的地，有可能是终点
            if(it == st.end()){
                st.insert(paths[i][1]);
            }
        }
        // 处理出发站
        for(int i = 0; i < size; ++i){
            auto it = st.find(paths[i][0]);  // 目的地成为了出发地，不可能是终点
            if(it != st.end()){
                st.erase(it);
            }
        }
        return *(st.begin());
    }
};
// @lc code=end
/*
[["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
[["B","C"],["D","B"],["C","A"]]
[["A","Z"]]
[["pYyNGfBYbm","wxAscRuzOl"],["kzwEQHfwce","pYyNGfBYbm"]]
*/
