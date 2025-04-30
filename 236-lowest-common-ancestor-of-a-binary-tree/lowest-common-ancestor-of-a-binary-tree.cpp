/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      bool solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (!root) return false;

        bool self = (root->val == p->val || root->val == q->val);
        bool left = solve(root->left, p, q, ans);
        bool right = solve(root->right, p, q, ans);

        if ((left && right) || (self && right) || (self && left)) {
            ans = root;
            return true;
        }

        return self || left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         TreeNode* ans = nullptr;
        solve(root, p, q, ans);
        return ans;
    }
};
