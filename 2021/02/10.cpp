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
        unordered_map<Node*, Node*> nodeMap;
        
        // Create a "fake head" so it won't need to handle the first node separatedly
        Node* newRoot = new Node(0);
        
        Node* newNode = newRoot;
        Node* oldNode = head;
        
        while (oldNode) {
            // Check if this node wasn't already created
            if (nodeMap.count(oldNode) == 0)
                nodeMap[oldNode] = new Node(oldNode->val);
                
            newNode->next = nodeMap[oldNode];
            newNode = newNode->next;
            
            // Create node reference in case it is after the current node
            if (oldNode->random && nodeMap.count(oldNode->random) == 0) 
                nodeMap[oldNode->random] = new Node(oldNode->random->val);
            
            newNode->random = nodeMap[oldNode->random];
            
            oldNode = oldNode->next;
        }
        
        return newRoot->next;
    }
};
