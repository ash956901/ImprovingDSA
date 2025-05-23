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
     void inorder(TreeNode* root,vector<int> &in){
        if(!root){
            return;
        }
        
        inorder(root->left,in);
        
        in.push_back(root->val);
        
        inorder(root->right,in);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        int i=0;
        for( i=0;i<k-1;i++);
        return in[i];
    }
};