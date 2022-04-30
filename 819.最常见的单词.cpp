/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}
// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> st(banned.begin(), banned.end());
        map<string, int> m;
        string word = "";
        vector<char> marks = {' ', '!', '?', '\'', ',', ';', '.'};
        for(int i = 0; i < paragraph.size(); ++i){
            if(find(marks.begin(), marks.end(), paragraph[i]) != marks.end()){
                if(word != "" && st.find(word) == st.end()){
                    // cout << word << endl;
                    ++m[word];
                }
                word = "";
            }else{
                if(paragraph[i] < 97){
                    word += paragraph[i] + 32;
                }else{
                    word += paragraph[i];
                }
            }
        }
        if(word != "" && st.find(word) == st.end()){
            ++m[word];
        }
        int maxCount = 0;
        for(auto [k, v] : m){
            if(v > maxCount){
                word = k;
                maxCount = v;
            }
        }
        return word;
    }
};
// @lc code=end

