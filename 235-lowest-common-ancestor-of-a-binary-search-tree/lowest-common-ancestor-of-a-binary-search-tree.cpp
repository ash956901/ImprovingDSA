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
    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==nullptr) return nullptr;

        if(root->val>p->val && root->val > q->val){
            return solve(root->left,p,q);
        }
         if(root->val<p->val && root->val < q->val){
            return solve(root->right,p,q);
        }

        if(root->val==p->val && (root->val > q->val || root->val < q->val)){
            return p;
        }

        if(root->val==q->val && (root->val > p->val || root->val < p->val)){
            return q;
        }

        if((root->val>p->val && root->val<q->val )|| (root->val <p->val && root->val>q->val)){
            return root;
        }

        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=solve(root,p,q);
        return ans;
    }
};