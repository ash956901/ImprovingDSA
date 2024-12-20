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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> lot;
        lot.push(root);
        lot.push(NULL);
        int level=0;
        vector<int> nodeVal;
        int vPointer;
        while(!lot.empty()){
            TreeNode* temp=lot.front();
            lot.pop();

            //if odd level
            if(temp!=NULL && (level&1)){
                temp->val=nodeVal[vPointer];
                vPointer--;
            }

            if(temp==NULL){
                level++;
                if(level%2==0) nodeVal.clear();
                if(level&1) vPointer=nodeVal.size()-1;
                if(!lot.empty()){
                    lot.push(NULL);
                }
                
            }

            else{
                if(temp->left!=NULL){
                lot.push(temp->left);
                if(level%2==0){
                    nodeVal.push_back(temp->left->val);
                }
            }
            if(temp->right!=NULL){
                lot.push(temp->right);
                 if(level%2==0){
                    nodeVal.push_back(temp->right->val);
                }
            }
            }
            
        }

        return root;
    }
};