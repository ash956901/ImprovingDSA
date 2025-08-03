class Solution {
public:
    int parent[1000000];
    int rank[1000000];

    void makeSet(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }

    void merge(int u,int v){
        int x=find(u);
        int y=find(v);

        if(x<y){
            parent[x]=y;
        }
        else if(y>x){
            parent[y]=x;
        }
        else{
            parent[y]=x;
            rank[x]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        makeSet(n);

        unordered_map<string,int> emailToIndex;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(emailToIndex.count(accounts[i][j])){
                    merge(i,emailToIndex[accounts[i][j]]);
                }
                else{
                    emailToIndex[accounts[i][j]]=i;
                }
            }
        }

        unordered_map<int,set<string>> merged;
        for(auto [email,idx]:emailToIndex){
            int i=find(idx);
            merged[i].insert(email);
        }


        vector<vector<string>> result;
        for(auto [root,emails]:merged){
            vector<string> acc;
            acc.push_back(accounts[root][0]);
            acc.insert(acc.end(),emails.begin(),emails.end());
            result.push_back(acc);
        }

        return result;


    }   
};