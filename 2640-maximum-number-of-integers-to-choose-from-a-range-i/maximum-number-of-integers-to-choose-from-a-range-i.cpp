class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> check;
        for(auto i:banned){
            check[i]++;
        }

        int count=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(!check.count(i)) sum+=i;
            if(sum>maxSum) break;
            if(!check.count(i))count+=1;
        }


        return count;
    }
};