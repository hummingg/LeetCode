/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <iostream>
#include <deque>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:

    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int old = x;
        int pali = 0;
        while(x > 0){
            if((INT_MAX - x % 10) / 10.0 < pali){
                return false;
            }
            pali = pali * 10 + x % 10;
            x = x / 10;
        }

        return old == pali;
    }


    bool isPalindrome1(int x) {
        if(x < 0){
            return false;
        }

        deque<int> d;

        while(x > 0){
            d.push_front(x % 10);
            x = x / 10;
        }
        while(d.size() > 1){
            if(d.front() != d.back()){
                return false;
            }else{
                d.pop_front();
                d.pop_back();
            }
        }
        
        return true;
    }
};
// digits 1
// digits digits
// @lc code=end

