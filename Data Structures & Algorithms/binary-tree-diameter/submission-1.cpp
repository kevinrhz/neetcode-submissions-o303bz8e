/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Map stores the computed data for each node: {height, max_diameter_in_subtree}
        unordered_map<TreeNode*, pair<int, int>> mp;
        
        // Base case: elegantly handles leaf node children without extra if-statements
        mp[nullptr] = {0, 0}; 
        
        stack<TreeNode*> stack;
        stack.push(root);

        // Simulate Post-Order Traversal (Left -> Right -> Node)
        while (!stack.empty()) {
            TreeNode* node = stack.top(); // Peek, don't pop yet! We must process children first.

            // 1. Drill down LEFT: If left child exists and hasn't been processed yet
            if (node->left && mp.find(node->left) == mp.end()) {
                stack.push(node->left);
            } 
            // 2. Drill down RIGHT: If right child exists and hasn't been processed yet
            else if (node->right && mp.find(node->right) == mp.end()) {
                stack.push(node->right);
            } 
            // 3. Process NODE: Both children are either null or already in the map
            else {
                node = stack.top();
                stack.pop(); // Now we can safely pop

                // Fetch children's data (if a child is null, it pulls {0,0} from our base case)
                auto[leftHeight, leftDiameter] = mp[node->left];
                auto[rightHeight, rightDiameter] = mp[node->right];

                // Calculate height to pass up to the parent
                int height = 1 + std::max(leftHeight, rightHeight);
                
                // Diameter is the max of: 
                // 1) Path curving through current node (leftHeight + rightHeight)
                // 2) Best diameter hiding entirely in the left subtree
                // 3) Best diameter hiding entirely in the right subtree
                int diameter = max(leftHeight + rightHeight,
                               max(leftDiameter, rightDiameter));

                // Cache the results so this node's parent can use them
                mp[node] = {height, diameter};
            }
        }
        
        // Return the diameter specifically calculated for the root
        return mp[root].second;
    }
};