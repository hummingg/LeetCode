/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // 86 20; 86 30;
    NestedInteger deserialize(string s) {
        // cout << "开始：" << s << endl;
        // single integer
        if(s[0] != '['){
            return NestedInteger(getNum(s));
        }

        // 必然有一层括号
        NestedInteger ni;
        // 按顶级','分割
        // vector<string> vs;
        string str = "";
        int deepBracket = 0;
        for(int i = 1; i < s.size()-1; ++i){
            if(s[i] == '['){
                ++deepBracket;
            }else if(s[i] == ']'){
                --deepBracket;
            }
            str += s[i];
            if(deepBracket == 0 && (s[i+1] == ',' || s[i+1] == ']')){
                ni.add(deserialize(str));
                str = "";
                deepBracket = 0;
                ++i;    // 跳过 ',' ']'
            }
        }
        return ni;
    }

    int getNum(string s){
        int sign = 1, ret = 0, begin = 0;
        if(s[0] == '-'){
            sign = -1;
            begin = 1;
        }
        for(int i = begin; i < s.size(); ++i){
            int num = s[i] - '0';
            ret = ret * 10 + num;
        }
        return ret * sign;
    }
};
// @lc code=end
/*
""324"\n
"-324"\n
"[123,[456,[789]]]"\n
"[123,[456,[789,[123,[456]]]]]"\n
"[123,456,[789,123,[456]]]""
*/

