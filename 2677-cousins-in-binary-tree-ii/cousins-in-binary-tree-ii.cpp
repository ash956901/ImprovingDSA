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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        unordered_map<int,int> levelSum;
        int level=1;
        int sum=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL){
                levelSum[level]=sum;
                sum=0;
                level+=1;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                    sum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

            }
        }
        q.push(root);
        q.push(NULL);
         level=1;
         while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL){
                level+=1;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                int siblingSum=0;
                if(temp->left){
                    q.push(temp->left);
                     siblingSum+=temp->left->val;
                }
                if(temp->right){
                    q.push(temp->right);
                    siblingSum+=temp->right->val;
                }

                if(siblingSum){
                    int diff=levelSum[level+1]-siblingSum;
                    if(temp->left){
                        temp->left->val=diff;
                    }
                     if(temp->right){
                        temp->right->val=diff;
                    }
                }

            }
        }


        root->val=0;
        return root;
    }
};