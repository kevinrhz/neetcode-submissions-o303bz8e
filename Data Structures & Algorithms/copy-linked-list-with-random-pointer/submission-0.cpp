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
        // create the map to store old to new copy nodes. initialize null key to null value
        std::unordered_map<Node*, Node*> oldToCopy; // {old node: new node}
        oldToCopy[NULL] = NULL;

        // FIRST PASS
        // populate the hash map with old node as key and new copy as value. blank canvas, no pointers yet, just nodes
        Node* cur = head;
        while (cur != NULL) {
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        // SECOND PASS
        // reset cur back to head
        cur = head;
        while (cur != NULL) {
            Node* copy = oldToCopy[cur]; // set copy to the cur key we are copying
            copy->next = oldToCopy[cur->next]; // copy next pointer
            copy->random = oldToCopy[cur->random]; // copy random pointer
            cur = cur->next; // iterate cur
        }

        return oldToCopy[head];
    }
};
