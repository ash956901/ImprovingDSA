/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2){
            return true;
        }
        if(!r1||!r2){
            return false;
        }

        cout<<"r1:"<<r1->val<<endl;
        cout<<"r2:"<<r2->val<<endl;

        
      
        int count=0;
        if(!r1->left) count+=1;
         if(!r1->right) count+=1;
          if(!r2->left) count+=1;
           if(!r2->right) count+=1;

        if(count==1||count==3){
            return false;
        }

        bool a=false;
        bool b=false;

        //all four exist 
        if(r1->left && r2->left && r1->right && r2->right){
            if(r1->left->val==r2->left->val){
                if(r1->right->val==r2->right->val){
                    a=solve(r1->left,r2->left);
                     b=solve(r1->right,r2->right);

                }
            }
            else{
                //swap
                TreeNode* temp=r1->left;
                r1->left=r1->right;
                r1->right=temp;
                  if(r1->left->val==r2->left->val){
                if(r1->right->val==r2->right->val){
                    a=solve(r1->left,r2->left);
                     b=solve(r1->right,r2->right);

                }
             }
            }
        }

        //only two exist 
        else if(r1->left && r2->left){
            if(r1->left->val==r2->left->val){
                if(!r1->right && !r2->right){
                     a=solve(r1->left,r2->left);
                     b=true;
                     }
            }
        }

         else if(r1->right && r2->right){
            if(r1->right->val==r2->right->val){
                if(!r1->left && !r2->left){
                     a=solve(r1->right,r2->right);
                     b=true;
                     }
            }
        }

        //only two ->need to swap
        else if(r1->left && r2->right ){
            if(r1->left->val==r2->right->val){
                if(!r1->right && !r2->left){
                    TreeNode* temp=r1->left;
                    r1->right=temp;
                    r1->left=NULL;
                    a=true;
                    b=solve(r1->right,r2->right);
                }
            }
        }

         else if(r1->right && r2->left ){
            if(r1->right->val==r2->left->val){
                if(!r1->left && !r2->right){
                    TreeNode* temp=r1->right;
                    r1->left=temp;
                    r1->right=NULL;
                    b=true;
                    a=solve(r1->left,r2->left);
                    b=true;
                }
            }
        }

        else if(!r1->left||!r2->left||!r1->right||!r2->right) return true;
         cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl;
        return a&&b;

    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            if(root1->val!=root2->val){
                return false;
            }
        }
        else{
            if(!root1 && !root2) return true;
            if(!root1 || !root2) return false;
        }
        return solve(root1, root2);
    }
};