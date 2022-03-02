/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
 */
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
class Solution {
public:
    //55 73;
    int pairSum(ListNode* head) {
        ListNode* p = head;
        stack<int> stk;
        int count = 0;
        while(p != nullptr){
            count++;
            p = p->next;
        }
        int i = 0;
        int maxSum = INT_MIN;
        p = head;
        while(p != nullptr){
            if(i < count / 2){
                i++;
                stk.push(p->val);
            }else{
                int sum = p->val + stk.top();
                stk.pop();
                maxSum = maxSum > sum ? maxSum : sum;
            }
            p = p->next;
        }
        return maxSum;
    }
};
// @lc code=end

