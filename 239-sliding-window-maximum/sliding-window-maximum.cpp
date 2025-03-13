class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      queue<int> q;
      priority_queue<int> pq;
      unordered_map<int,int> freq;

      for(int i=0;i<k;i++){
        q.push(nums[i]);
        freq[nums[i]]++;
        pq.push(nums[i]);
      }

      vector<int> ans;

      ans.push_back(pq.top());

      //now for the rest of the window
      for(int i=k;i<nums.size();i++){
            int qF=q.front();
            q.pop();
            freq[qF]--;


            q.push(nums[i]);
            freq[nums[i]]++;
            pq.push(nums[i]);

            //update max 
            while(freq[pq.top()]==0) {
                pq.pop();
            }

            ans.push_back(pq.top());
      } 


      return ans;


    }
};