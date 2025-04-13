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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode* node=front.first;
            int hd=front.second.first;
            int lvl=front.second.second;
            m[hd][lvl].push_back(node->val);

            if(node->left){
                q.push(make_pair(node->left,make_pair(hd-1,lvl+1)));
            }

             if(node->right){
                q.push(make_pair(node->right,make_pair(hd+1,lvl+1)));
            }
        }

        vector<int> hold;
        for(auto i:m){
            for(auto j:i.second){
                int start=hold.size();
                for(auto k:j.second){
                    hold.push_back(k);
                }

                sort(hold.begin()+start,hold.end());

            }
            ans.push_back(hold);
            hold.clear();
        }

        return ans;
    }
};