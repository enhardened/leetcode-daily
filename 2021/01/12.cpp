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
        ListNode* current;
        ListNode* prehead = new ListNode(0);
        ListNode* tail = prehead;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr) {
            current = new ListNode(carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0));
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            
            if (current->val > 9) {
                current->val -= 10;
                carry = 1;
            } else
                carry = 0;
            
            tail->next = current;
            tail = current;
        }
        
        if (carry)
            tail->next = new ListNode(carry);
        
        return prehead->next;
    }
};
