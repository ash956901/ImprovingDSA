/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   unordered_map<int,vector<int>> graph;

   void buildGraph(TreeNode* root,TreeNode* parent){
    if(root==nullptr) return;
    if(parent){
        graph[parent->val].push_back(root->val);
        graph[root->val].push_back(parent->val);

    }

    buildGraph(root->left,root);
    buildGraph(root->right,root);
    return;
   }


   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>  ans;
        buildGraph(root,nullptr);
        queue<pair<int,int>> q;
        q.push(make_pair(target->val,0));
        unordered_set<int> visited;
        visited.insert(target->val);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            int nodeVal=curr.first;
            int nodedist=curr.second;

            if(nodedist==k){
                ans.push_back(nodeVal);
            }
            else if(nodedist<k){
                for(auto i:graph[nodeVal]){
                    if(!visited.count(i)){
                        visited.insert(i);
                        q.push(make_pair(i,nodedist+1));
                    }
                }
            }
        }
        return ans;
    }
};