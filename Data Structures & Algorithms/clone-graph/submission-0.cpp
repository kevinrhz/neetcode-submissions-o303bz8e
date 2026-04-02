/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, std::unordered_map<Node*, Node*>& oldToNew) {
        if (!node) return nullptr;

        // if node is already in map, return already made copy
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // clone the current node and its value, store in copy. store it in map
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        // clone the current copy's neighbors edges
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        return copy;
    }
};
