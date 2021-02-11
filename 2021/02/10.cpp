/*
Problem: https://leetcode.com/explore/item/3635
Title: Copy List with Random Pointer
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        Node* newHead = new Node(head->val);
        
        Node* newNode = newHead;
        Node* oldNode = head;
        Node* counter;
        int count;
        
        while (oldNode->next != nullptr) {
            newNode->next = new Node(oldNode->next->val);
            
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        
        // rewind to find random nodes
        newNode = newHead;
        oldNode = head;
        
        while (oldNode != nullptr) {
            if (oldNode->random != nullptr) {
                // Find the position of the random node
                counter = head;
                count = 0;
                
                while (counter != oldNode->random) {
                    counter = counter->next;
                    ++count;
                }
                
                // Find the new random node by position
                counter = newHead;
                
                while (count > 0) {
                    counter = counter->next;
                    --count;
                }
                
                newNode->random = counter;
            }
            
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        
        return newHead;
    }
};
