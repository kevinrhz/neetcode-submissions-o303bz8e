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
    int maxDepth(TreeNode* root) {
        // OPTIMIZATION: Early exit prevents unnecessary queue allocation for empty trees
        if (!root) return 0; 
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0; // Tracks the current depth
        
        // Process the tree level by level
        while (!q.empty()) {
            // Cache the number of nodes at the current level
            int size = q.size(); 
            
            // Iterate through all nodes on this specific level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Push children to queue to be processed in the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Increment depth after completely processing one full level
            ++level;
        }
        
        return level;
    }
};
