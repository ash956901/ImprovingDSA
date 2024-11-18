class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> check;
        int count=0;
        int maxi=INT_MIN;
        int dis=0;
        int i=0;
        for(int j=0;j<fruits.size();j++){
            check[fruits[j]]++;
            count++;
            if(check[fruits[j]]==1) dis++;
            while(dis>2){
                check[fruits[i]]--;
                if(check[fruits[i]]==0) dis--;
                count--;
                i++;
            } 
            maxi=max(maxi,count);
        }

        return maxi;
    }
};