class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(nums[i],i));
        }
        vector<int> ankush(nums.size(),0);
        long long score=0;
        int mark=0;
        while(mark!=nums.size()){
            long long temp=pq.top().first;
            long long index=pq.top().second;
            pq.pop();

            if(!ankush[index]){
                ankush[index]=1;
                if(index-1>=0 && !ankush[index-1]) {
                    ankush[index-1]=1;
                    mark++;
                    }
                if(index+1<nums.size() && !ankush[index+1]){
                    ankush[index+1]=1;
                    mark++;
                    }
                score+=temp;
                mark++;
            }
        }

        return score;
    }
};