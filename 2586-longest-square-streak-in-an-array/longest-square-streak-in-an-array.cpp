class Solution {
public:
    int squarebs(vector<int>& nums,int i){
        long long stf=pow(nums[i],2);

        int s=i;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==stf) return mid;
            else if(nums[mid]>stf) {
                e=mid-1;
            }
            else if(nums[mid]<stf){
               s=mid+1;
            }
            mid=s+(e-s)/2;
        }

        return -1;
    }
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        // sort the array
        sort(nums.begin(), nums.end());

        // run a loop over all elements and run binary Search also keep max
        // count
        int maxi = INT_MIN;
        vector<int> visited(n);

        for (int i = 0; i < n; i++) {
            int curr_element = nums[i];
            int count = 1;
            if (!visited[i]) {
                visited[i]=1;
                // search for its longest square sequence
                int check=squarebs(nums,i);
                while (check!= -1) {
                    // get the index and mark as visited
                    visited[check]=1;
                    // increment the counter
                    count++;
                     // call the function
                    check=squarebs(nums,check);
                }
            }


            maxi=max(maxi,count);
        }

        if(maxi<2) return -1;

        return maxi;
    }
};