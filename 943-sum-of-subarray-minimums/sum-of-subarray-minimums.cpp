#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        stack<int> ns;

        for(int i=0;i<arr.size();i++){
            while(!ns.empty() && arr[ns.top()]>=arr[i]){
                int nsTop=ns.top();
                ns.pop();
                int step=nsTop?nsTop+1:1;
                if(!ns.empty()){
                    step=(nsTop-ns.top());
                }
                //the number of subarrays for which it is minimum, is (i-pse)*(nse-i)
                sum=(sum%MOD)+(((i-nsTop)*step)*arr[nsTop])%MOD;
            }
            ns.push(i);
        }
        int n=arr.size();
        
        while(!ns.empty()){
            int nsTop=ns.top();
            ns.pop();
            int np=(n-nsTop);
            int pp=(!ns.empty())?(nsTop-ns.top()):(nsTop+1);
            sum=(sum%MOD)+((long long)(np*pp)%MOD*arr[nsTop]%MOD)%MOD;
        }

        return (int)(sum%MOD);
    }
};