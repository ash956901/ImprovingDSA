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
    
    vector<int> preorderTraversal(TreeNode* root) {
       
        vector<int> ans;
         if(root==NULL) return ans;
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,1));
        while(!s.empty()){
            auto top=s.top();
            s.pop();

            if(top.second==1){
                 ans.push_back(top.first->val);
            }
           

            if(top.second==1){
                s.push(make_pair(top.first,2));
                if(top.first->left){
                    s.push(make_pair(top.first->left,1));
                }
            }

            else if(top.second==2){
                if(top.first->right){
                    s.push(make_pair(top.first->right,1));
                }
            }

           
        }
        return ans;
    }
};