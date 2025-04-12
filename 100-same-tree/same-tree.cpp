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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }

        if(!p || !q){
            return false;
        }

        bool a=false;
        bool b=false;

        if(p->val==q->val){
            a=isSameTree(p->left,q->left);
            b=isSameTree(p->right,q->right);
        }
        else{
            return false;
        }


        return a&&b;

    }
};