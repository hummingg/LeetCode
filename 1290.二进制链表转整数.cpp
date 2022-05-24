/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 100 42;
    int getDecimalValue(ListNode* head) {
        ListNode* p = head;
        int sum = 0;
        while(p){
            sum = (sum << 1) + p->val;
            p = p->next;
        }
        return sum;
    }

    int getDecimalValue1(ListNode* head) {
        ListNode* p = head;
        int size = 0;
        while(p){
            p = p->next;
            ++size;
        }
        --size;
        int sum = 0;
        p = head;
        while(p){
            sum += p->val << size;
            p = p->next;
            --size;
        }
        return sum;
    }
};
// @lc code=end
/*
[1,0,1]\n
[0]\n
[1]\n
[1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]\n
[0,0]
*/
