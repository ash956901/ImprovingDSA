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
    int minSwaps(vector<pair<int,int>> &unsort){
        int n=unsort.size();
        sort(unsort.begin(),unsort.end());
        //make visited array of the same size 
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(unsort[i].second==i || visited[i]){
                continue;
            }

            int j=i;
            int cycle_size=0;
            while(!visited[j]){
                visited[j]=true;
                j=unsort[j].second;
                cycle_size++;
            }

            if(cycle_size>0){
                ans+=(cycle_size-1);
            }

        }
        return ans;

    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int ans=0;
        vector<pair<int,int>> curr;
        int i=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp==NULL){
                int adder=minSwaps(curr);
                ans+=adder;
                curr.clear();
                i=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left!=NULL){
                    q.push(temp->left);
                    curr.push_back(make_pair(temp->left->val,i));
                    i++;
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                     curr.push_back(make_pair(temp->right->val,i));
                    i++;
                }
            }
        }

        return ans;
    }
};