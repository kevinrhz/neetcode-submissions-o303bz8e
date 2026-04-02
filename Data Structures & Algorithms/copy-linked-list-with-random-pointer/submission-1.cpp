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
        // Edge case: Empty list
        if (head == nullptr) return nullptr;

        // Map to translate: Original Node Address -> Copied Node Address
        std::unordered_map<Node*, Node*> mp;
        
        // Safety Shield: Map nullptr to nullptr so our Pass 2 wiring doesn't crash
        // when a node's next or random points to null.
        mp[nullptr] = nullptr; 

        // Pass 1: The Factory Floor
        // Create a "naked" copy of every node (just the value, no arrows yet)
        Node* curr = head;
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: The Wiring Phase
        // Look up the copies in the map and connect their arrows
        curr = head;
        while (curr != nullptr) {
            mp[curr]->next = mp[curr->next];       // Connect the 'next' arrow
            mp[curr]->random = mp[curr->random];   // Connect the 'random' arrow
            curr = curr->next;                     // Move to the next original node
        }

        // The map perfectly translates the old head address to the new head address
        return mp[head];
    }
};
