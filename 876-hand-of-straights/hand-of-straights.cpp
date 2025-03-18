class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> check;
        for(int i=0;i<hand.size();i++){
            check[hand[i]]++;
            if(check[hand[i]]==1) pq.push(hand[i]);
        }

        while(!pq.empty()){
            int top=pq.top();
            pq.pop();

            if(check[top]!=0){
                //can be used as top
                //decrease count 
                check[top]--;
                if(check[top]!=0) pq.push(top);

                //ran loop till n consecutive if not present then 
                for(int i=1;i<groupSize;i++){
                    if(check.count(top+i)==0 || check[top+i]==0) return false;
                    else{
                        check[top+i]--;
                    }
                }

            }   
        }
        return true;



    }
};