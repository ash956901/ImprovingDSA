class Solution {
public:

    int parent[10000000];
    int setSize[10000000];

     void makeSet(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            setSize[i]=1;
        }
    }

     int findParent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=findParent(parent[i]);
    }

     void unionMST(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        
        if(pu==pv) return ;
        if(pu<pv){
            parent[pu]=pv;
            setSize[pv]+=setSize[pu];
        }
        else{
            parent[pv]=pu;
            setSize[pu]+=setSize[pv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        unordered_set<int> components;

        makeSet(n);

        for(auto &e:connections){
            unionMST(e[0],e[1]);
        }

        for(int i=0;i<n;i++){
            components.insert(findParent(i));
        }

        return components.size()-1;
    }
};