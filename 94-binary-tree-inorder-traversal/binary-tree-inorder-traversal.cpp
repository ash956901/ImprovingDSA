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
    

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,0));
        while(!s.empty()){
            auto top=s.top();
            s.pop();

            if(top.second==0){
                TreeNode* temp=top.first;
                while(temp!=NULL){
                    s.push(make_pair(temp,1));
                   temp=temp->left;
                }
            }
            else if(top.second==1){
                //all left explored, now add it and push its right chhild if it has one
                ans.push_back(top.first->val);
                if(top.first->right!=NULL){
                    s.push(make_pair(top.first->right,0));
                }
            }
           
        }
        return ans;
    }
};