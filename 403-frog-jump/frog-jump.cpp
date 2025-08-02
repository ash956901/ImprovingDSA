class Solution {
public:
    bool dfs(int index,int lastJump,vector<int> &stones,unordered_map<int,int> &stoneIndex,unordered_map<long long,bool> &memo){
        if(index==stones.size()-1) return true;
       
        //create unique key, since unordered map doesnst support it bydefault
        //first 32 bits are index,last 32 bits lastJump( 64 bit key)
        long long key=((long long) index <<32) | lastJump; 
        if(memo.count(key)) return memo[key];

        for(int jump=lastJump-1;jump<=lastJump+1;jump++){
            if(jump<=0) continue;
            int nextStep=stones[index]+jump;
            if(stoneIndex.count(nextStep)){
                if(dfs(stoneIndex[nextStep],jump,stones,stoneIndex,memo)){
                    return memo[key]=true;
                }
            }
        }
        return memo[key]=false;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> stoneIndex;
        for(int i=0;i<stones.size();i++){
            stoneIndex[stones[i]]=i;
        }
        unordered_map<long long,bool> memo;
        return dfs(0,0,stones,stoneIndex,memo);
    }
};