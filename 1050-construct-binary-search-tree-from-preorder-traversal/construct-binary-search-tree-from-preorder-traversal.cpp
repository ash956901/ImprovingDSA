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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* curr=new TreeNode(preorder[0]);
        TreeNode* root=curr;
        for(int i=1;i<preorder.size();i++){
            if(preorder[i]<curr->val){
                TreeNode* temp=new TreeNode(preorder[i]);
                curr->left=temp;
                s.push(curr);
                curr=temp;
            }
            else if(preorder[i]>curr->val){
                    while(!s.empty() && preorder[i]>s.top()->val){
                        curr=s.top();
                        s.pop();
                        
                    }
                    TreeNode* temp=new TreeNode(preorder[i]);
                    curr->right=temp;

                    curr=temp;
               
                }
                if(!s.empty())
                    cout<<s.top()->val<<" ";
            
        }

        return root;
    }
};