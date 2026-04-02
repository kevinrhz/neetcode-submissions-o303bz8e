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
        if (!root) return 0;

        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int res = 0;

        while (!stack.empty()) {
            std::pair<TreeNode*, int> cur = stack.top();
            stack.pop();
            TreeNode* node = cur.first;
            int depth = cur.second;

            if (node) {
                res = std::max(res, depth);
                stack.push({node->left, depth + 1});
                stack.push({node->right, depth + 1});
            }
        }
        return res;
    }
};
