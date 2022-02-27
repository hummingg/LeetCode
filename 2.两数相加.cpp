/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *l3 = nullptr, *rear = l3;
        int partSum = 0, carry = 0;

        while(p1 != nullptr && p2 != nullptr){
            partSum = p1->val + p2->val + carry;
            carry = partSum / 10;

            if(l3 == nullptr){
                l3 = new ListNode(partSum % 10);
                rear = l3;
            }else{
                rear->next = new ListNode(partSum % 10);
                rear = rear->next;
            }

            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode *p = p1 != nullptr ? p1 : p2;
        while(p != nullptr){
            partSum = carry + p->val;
            carry = partSum/10;
            rear->next = new ListNode(partSum%10);
            rear = rear->next;
            p = p->next;
        }
        if(carry != 0){
            rear->next = new ListNode(carry);
            rear = rear->next;
        }

        return l3;
    }
};
// max(m,n) max(m,n)
// @lc code=end

