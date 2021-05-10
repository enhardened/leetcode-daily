/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3601/
Title: Add Two Numbers
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode** tail = &head;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr) {
            *tail = new ListNode(carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0));
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            
            if ((*tail)->val > 9) {
                (*tail)->val -= 10;
                carry = 1;
            } else
                carry = 0;
            
            tail = &(*tail)->next;
        }
        
        if (carry)
            *tail = new ListNode(carry);
        
        return head;
    }
};
