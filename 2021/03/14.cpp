// Problem: https://leetcode.com/explore/item/3671
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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head->next)
            return head;
        
        ListNode *l = head,
                 *r = head,
                 *a;
        
        // Find the element before the one from the beginning that needs to be swapped
        while (--k)
            r = r->next;
        
        a = r;
        
        // Find the element before the one from the need that needs to be swapped
        while (r->next) {
            r = r->next;
            l = l->next;
        }
        
        int tmp = a->val;
        
        a->val = l->val;
        l->val = tmp;
        
        return head;
    }
};
