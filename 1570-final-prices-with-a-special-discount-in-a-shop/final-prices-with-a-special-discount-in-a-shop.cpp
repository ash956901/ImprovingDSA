class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i=0;i<prices.size();i++)
        {
            int temp=-1;
            for(int j=i+1;j<prices.size();j++)
            {
                if(prices[i]>=prices[j])
                {
                    temp=prices[i]-prices[j];
                    break;
                }
            }
            if(temp!=-1)
            {
                ans.push_back(temp);
            }
            else
            {
                ans.push_back(prices[i]);
            }
        }
        return ans;
    }
};