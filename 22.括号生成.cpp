/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start

// static bool myfunc(string i, string j)
// {
//     return i == j;
// }

class Solution {
private:
    string s;
    int left = 0;
    int right = 0;
public:
    // 
    // vector<string> generateParenthesis(int n) {

    // }

    // 方法欠佳
    // 卡特兰数
    // 每个位置都要满足 左>=右
    // n个左括号用完就确定了
    // 23 86;
    vector<string> generateParenthesis(int n) {
        // set<string> v;
        set<string> st;
        vector<string> v;
        if(n == 1){
            v.push_back("()");
            return v;
        }
        // ()
        // ()()  (())
        // "((()))","(()())","(())()","()(())","()()()"
        auto vs = generateParenthesis(n-1);
        for(int i=0; i < vs.size(); i++){
            // cout << vs[i] << endl;
            for(int j = 0; j <= vs[i].size(); j++){
                string str = vs[i];
                st.insert(str.insert(j, "()"));    // 此方法会改变s本身
            }
        }
        // v.erase(unique(v.begin(), v.end(), myfunc), v.end());
        // cout << v.size() << endl;
        // for(int i=0; i < v.size(); i++){
        //     cout << v[i] << endl;
        // }
        // for(auto it : st){
        //     cout << it << endl;
        // }
        v.assign(st.begin(), st.end());
        return v;
    }


};

// int main(){
//     Solution s;
//     s.generateParenthesis(3);
//     return 0;
// }
// @lc code=end

