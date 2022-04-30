/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
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
    int lengthLongestPath(string input) {
        lengthPath(input, 0);
        return 0;
    }

    // 前面的长度
    int lengthPath(string input, int depth){
        string sep = "\n" + string(depth, '\t');
        cout << split(input, sep) << endl;
        return 0;
    }

    vector<string> split(string input, string sep){
        vector<string> ret;
        int begin = 0;
        int found = input.find(sep, begin);
        while(found != string::npos){
            int end = found+sep.size();
            if(end < input.size() && input[end] != '\t'){
                cout << input.substr(begin, found-begin+1) << endl;
                ret.push_back(input.substr(begin, found));
            }
            begin = end;
            found = input.find(sep, begin);
        }
        return ret;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> v = {1, 2};
    string str = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    cout << s.lengthLongestPath(str) << endl;
    return 0;
}
