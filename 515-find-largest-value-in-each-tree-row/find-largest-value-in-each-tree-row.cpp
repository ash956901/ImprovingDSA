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
    vector<int> largestValues(TreeNode* root) {
     
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        if(root==NULL) return ans;
        int maxi=INT_MIN;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=NULL){
                maxi=max(maxi,temp->val);
            }
            if(temp==NULL){
                ans.push_back(maxi);
                maxi=INT_MIN;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }


        return ans;
    }
};