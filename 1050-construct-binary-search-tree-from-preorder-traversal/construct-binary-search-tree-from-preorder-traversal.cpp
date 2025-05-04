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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* t=new TreeNode(val);
            return t;
        }

        if(root->val>val){
            root->left=insertIntoBST(root->left,val);
        }
        if(root->val<val){
            root->right=insertIntoBST(root->right,val);
        }
        

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* temp=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            temp=insertIntoBST(temp,preorder[i]);
        }  
        return temp;  
        }
};