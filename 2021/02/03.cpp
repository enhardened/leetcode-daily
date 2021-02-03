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
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> viewedNodes;
        
        while (head) {
            if (viewedNodes.count(head))
                return true;
            
            viewedNodes.insert(head);
            head = head->next;
        }
        
        return false;
    }
};
