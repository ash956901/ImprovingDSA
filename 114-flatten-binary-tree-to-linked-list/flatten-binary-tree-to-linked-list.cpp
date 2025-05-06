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
    // TreeNode* prev=nullptr;
    // void solve(TreeNode* root){
    //     if(root==nullptr) return;

    //     solve(root->right);
    //     solve(root->left);
        
    //     root->right=prev;
    //     root->left=nullptr;

    //     prev=root;

    // }
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
      stack<TreeNode*> s;
      s.push(root);
      while(!s.empty()){
        auto top=s.top();
        s.pop();

        if(top->right){
            s.push(top->right);
        }

         if(top->left){
            s.push(top->left);
        }

        if(!s.empty()){
            top->right=s.top();
        }
        top->left=nullptr;
       
      }
    }
};