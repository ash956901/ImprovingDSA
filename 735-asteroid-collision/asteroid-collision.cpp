class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            int curr=asteroids[i];
            bool flag=false;
            while(!s.empty() &&  (s.top()>0 && curr<0)){
                if(abs(s.top())==abs(curr)){
                    s.pop();
                    flag=true;
                    break;
                }
                else{
                    if(abs(curr)>abs(s.top())){
                        s.pop();
                    }
                    else{
                         curr=s.top();
                        s.pop();
                       
                    }
                }
            }
            if(!flag){
                 s.push(curr);
            }
           
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};