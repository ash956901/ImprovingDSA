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

    int search(vector<int>& inorder, int root, int l, int r){
        for(int i = l; i <= r; i++){
            if(inorder[i] == root){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postIndex, int l, int r){
        if(l>r) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int index = search(inorder, rootVal, l, r);

        
        root->right = solve(postorder, inorder, postIndex, index + 1, r);
        root->left = solve(postorder, inorder, postIndex, l, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int postIndex = postorder.size()-1;
        return solve(postorder, inorder, postIndex, 0, inorder.size() - 1);
    }
};



    

    