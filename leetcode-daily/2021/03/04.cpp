// Problem: Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Verify if there are two lists
        if (!headA || !headB)
            return nullptr;
        
        int lenA = 1,
            lenB = 1,
            diff;
        
        ListNode *refA = headA;
        ListNode *refB = headB;
        
        // Calculate lists sizes
        while (refA->next) {
            refA = refA->next;
            lenA++;
        }
        
        while (refB->next) {
            refB = refB->next;
            lenB++;
        }
        
        // Search for intersection starting from the same distance
        refA = headA;
        refB = headB;
        
        if (lenA > lenB) {
            diff = lenA - lenB;
            refA = headA;
            refB = headB;
        } else {
            diff = lenB - lenA;
            refA = headB;
            refB = headA;
        }
        // Now refA is the head of the longest list

        while (diff--)
            refA = refA->next;

        // Now refA is as far from the last node as refB
        // so, it's also the same distance from the intersection - if there is one
        // Ex.:
        //    refA
        //     |
        // 1 2 3 4
        //         8 9 10 
        //     5 6
        //     |
        //    refB
        
        while (refA) {
            if (refA == refB)
                return refA;
            
            refA = refA->next;
            refB = refB->next;
        }
        
        return nullptr;
    }
};
