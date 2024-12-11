class Solution {
public:
    bool check(string s,int mid){
        vector<int> count(26,0);
        int i=0;
        for(int j=0;j<s.size();j++){
            while(s[i]!=s[j]) i++;
            if(j-i+1>=mid) count[s[i]-'a']++;
            if(count[s[i]-'a']>2) return true;
        }


        return false;
    }
    int maximumLength(string s) {
        int l=1;
        int r=s.size();
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(s,mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }

        return ans;
    }
};