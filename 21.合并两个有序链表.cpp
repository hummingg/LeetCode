/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <class T> std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "]";
    }
    return out;
}

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
    // 93 71;
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode *h1 = list1, *h2 = list2, *head, *tail;
        // 不带头节点,特殊处理
        if(h1->val <= h2->val){
            tail = h1;
            h1 = h1->next;
        }else{
            tail = h2;
            h2 = h2->next;
        }
        head = tail;
        while(h1 && h2){
            if(h1->val <= h2->val){
                tail->next = h1;
                tail = tail->next;
                h1 = h1->next;
            }else{
                tail->next = h2;
                tail = tail->next;
                h2 = h2->next;
            }
        }
        if(h1){
            tail->next = h1;
        }
        if(h2){
            tail->next = h2;
        }
        return head;
    }

    // 93 66;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

