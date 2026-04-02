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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        std::stack<bool> visit;

        stack.push(root);
        visit.push(false);

        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            bool v = visit.top();
            stack.pop();
            visit.pop();

            if (cur) {
                if (v) {
                    res.push_back(cur->val);
                } else {
                    stack.push(cur);
                    visit.push(true);
                    stack.push(cur->right);
                    visit.push(false);
                    stack.push(cur->left);
                    visit.push(false);
                }
            }
        }

        return res;
    }
};