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
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        TreeNode* temp=root;
        while(temp!=nullptr){
            s.push(temp);
            temp=temp->left;
        }
    }
    
    int next() {
        TreeNode* temp=s.top();
        int ret=temp->val;
        s.pop();
        if(temp->right!=nullptr){
            temp=temp->right;
            while(temp!=nullptr) {
                s.push(temp);
                temp=temp->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        return false;
    }
};
