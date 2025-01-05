class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //learnt diff array concept today for efficient update of range based queries in O(1)
        vector<int> dArray(s.size()+1,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                dArray[shifts[i][0]]-=1;
                dArray[shifts[i][1]+1]+=1;
            }
            else{
                 dArray[shifts[i][0]]+=1;
                dArray[shifts[i][1]+1]-=1;
            }
        }

        for(int i=1;i<dArray.size();i++){
            dArray[i]+=dArray[i-1];
        }



        for(int i=0;i<s.size();i++){
            int inc=(s[i]-'a'+dArray[i])%26;
            if(inc<0){
                inc+=26;
            }
            s[i]='a'+inc;
        }

        return s;

    }
};