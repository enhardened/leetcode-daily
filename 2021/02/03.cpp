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
        ListNode *fast = head,
                 *slow = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                return true;
        }
        
        return false;
    }
};
