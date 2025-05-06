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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    void solve(TreeNode* root){
        if(root==nullptr) return;
        
        solve(root->left);
        if(prev!=nullptr && (root->val<prev->val)){
            if(first==nullptr){
                first=prev;
                middle=root;
            }

            else{
                last=root;
            }
        }
        prev=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=middle=nullptr;
        prev=new TreeNode(INT_MIN);
        solve(root);
        if(first&&last) swap(first->val,last->val);
        else if(first&&middle) swap(first->val,middle->val);
        return;
    }
};