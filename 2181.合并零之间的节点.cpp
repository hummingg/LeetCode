/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 */
#include <iostream>
#include <vector>
using namespace std;
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
    // 5 63; 25 62; 19 63;
    // 不delete: 10 90; 74 100;
    ListNode* mergeNodes(ListNode* head) {
        ListNode *result = head->next;  // head->val 必为0
        ListNode *tail = head, *p = result, *summed, *q; // p必不为0，为了代码好看暂时保留head

        while(p != nullptr){
            summed = p;   // 首个非0结点作为合并结点，以便固定result为新链表的头结点
            int sum = 0;   // 子链表各结点之和

            // 当前结点不为0，第一个不能删
            sum += p->val;
            p = p->next;
            while(p->val != 0){
                sum += p->val;
                q = p;
                p = p->next;
                delete(q);
            }

            // 当前结点为0
            summed->val = sum;
            summed->next = nullptr;
            tail->next = summed;
            tail = summed;
            q = p;
            p = p -> next;  // null 或 非0
            delete(q);
        }
        delete(head);

        return result;
    }
};

// int main(){
//     Solution s;
//     // [0,3,1,0,4,5,2,0]
//     // [0,1,0,3,0,2,2,0]
//     vector<int> v = {0,1,0,3,0,2,2,0};
//     ListNode *head = new ListNode(0, nullptr), *p=head, *q;
//     for(auto it = v.begin()+1; it != v.end(); it++){
//         // cout << *it << endl;
//         q = new ListNode(*it, nullptr);
//         p->next = q;
//         p = q;
//     }
//     // cout << "链表：" << endl;
//     // while(head != nullptr){
//     //     cout << head->val << endl;
//     //     head = head->next;
//     // }
//     cout << s.mergeNodes(head)->val << endl;
//     return 0;
// }
// @lc code=end

