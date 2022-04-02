/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    // 65 85; 74 52; 65 65;
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int index = 0;
        ListNode *p = list1;
        ListNode *p1;
        while(p){
            if(index == a-1){
                p1 = p;
            }else if(index == b+1){
                break;
            }
            p = p->next;
            index++;
        }
        // ListNode *p1 = p;   // 记录p的位置
        // while(p){
        //     if(index == b+1){
        //         break;
        //     }
        //     p = p->next;
        //     index++;
        // }
        
        ListNode *q = list2;
        while(q->next){
            q = q->next;
        }
        p1->next = list2;
        q->next = p;
        return list1;
    }
};
// @lc code=end

/* 
[0,1,2,3,4,5,6]\n2\n5\n[1000000,1000001,1000002,1000003,1000004]
*/