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

      TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIndex, int l, int r){
        if(l > r) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int index = search(inorder, rootVal, l, r);

        root->left = solve(preorder, inorder, preIndex, l, index - 1);
        root->right = solve(preorder, inorder, preIndex, index + 1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int preIndex = 0;
        return solve(preorder, inorder, preIndex, 0, preorder.size() - 1);
    }
};



  

   