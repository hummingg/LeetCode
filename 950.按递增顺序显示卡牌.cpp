/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 按递增顺序显示卡牌
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 13 5;
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 递归分治，一半一半处理
        sort(deck.begin(), deck.end());
        // print(deck);
        return recursion(deck);
    }

    vector<int> recursion(vector<int>& sortedDeck){
        int end = sortedDeck.size()-1;
        if(end < 2){    // 不多于2个元素的有序牌组，已经满足要求
            return sortedDeck;
        }
        vector<int> small;
        small.assign(sortedDeck.begin(), sortedDeck.begin() + end/ 2 + 1);
        // print(small);
        vector<int> big;
        big.assign(sortedDeck.begin() + end/ 2 + 1, sortedDeck.end());
        // print(big);
        big = recursion(big);
        if(small.size() > big.size()){  // 大的不够移动，第一张被移动2次
            big.insert(big.begin(), big.back());
            big.erase(big.end()-1);
        }
        for(int i = 0; i < big.size(); i++){
            small.insert(small.begin()+2*i+1, big[i]);
        }
        return small;
    }

    void print(vector<int>& v){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
// @lc code=end

