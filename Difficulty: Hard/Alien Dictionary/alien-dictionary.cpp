class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<int,list<int>> adj;
        unordered_map<int,int> indegree;
        unordered_set<int> present;
        
        for(auto w:words){
            for(auto c:w){
                present.insert(c-'a');
                indegree[c-'a']=0;
            }
        }
        
        
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int len=min(w1.length(),w2.length());
            bool found=false;
            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    int u=w1[j]-'a';
                    int v=w2[j]-'a';
                    if(find(adj[u].begin(),adj[u].end(),v)==adj[u].end()){
                        adj[u].push_back(v);
                        indegree[v]++;
                    }
                    found=true;
                    break;
                }
            }
            
            if(!found && w1.length()>w2.length()){
                return "";
            }
        }
        
        queue<int> q;
        
        for(auto i:present){
            if(!indegree[i]) q.push(i);
        }
        
        string result="";
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            result+=(char)(front+'a');
            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }

        return (result.length()==present.size())?result:"";
        
        
    }
};