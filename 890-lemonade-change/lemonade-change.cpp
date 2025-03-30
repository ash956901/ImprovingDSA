class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      vector<int> den(3,0);
      int change=0;
      for(auto i:bills){
        int curr=i;

        if(curr==5) den[0]++;
        if(curr==10) den[1]++;
        if(curr==20) den[2]++;


        int changeAmount=i-5;
        
        if(changeAmount==15){
            //10 5
            if(den[0]>=1 && den[1]>=1){
                den[0]--;
                den[1]--;
            }
            //5 5 5
            else if(den[0]>=3){
                den[0]-=3;
            }
             //false
            else{
                return false;
            }

           
        }
        else if(changeAmount==5){
            //5
            if(den[0]>=1){ den[0]--;}
            //false
            else{return false;}
        }
      }
      return true;
    }
};