/*
Problem: https://leetcode.com/problems/linked-list-cycle/
Title: 141. Linked List Cycle
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Time: O(n) 
Space: O(1)
n being the size of the linked list
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* verifier = new ListNode();
        ListNode* tmp;
        
        while (head) {
            if (head->next == verifier)
                return true;
            
            tmp = head->next;
            head->next = verifier;
            head = tmp;
        }
        
        return false;
    }
};
