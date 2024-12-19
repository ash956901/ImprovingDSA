class Solution {
public:
    int checkValidity(vector<vector<int>>& points,int x1,int x2,int y1,int y2){
        vector<vector<int>> vals={{x1,y1},{x2,y2},{x1,y2},{x2,y1}};
        for(auto it:points){
            if(it==vals[0]||it==vals[1]||it==vals[2]||it==vals[3]) continue;
            if((it[0]>=x1 && it[0]<=x2 )&& (it[1]>=y1 && it[1]<=y2)) return false;
        }
        return true;
    }
    int findThirdAndFourth(vector<vector<int>>& points,int x1,int y1,int y2){
        int x2=-1;
        int ans=-1;
        for(auto it:points){
            if(it[1]==y1&&it[0]!=x1){
                vector<int> target={it[0],y2};
                if(find(points.begin(),points.end(),target)!=points.end()){
                    x2=it[0];
                    if(x1>=x2) continue;
                    if(!checkValidity(points,x1,x2,y1,y2)){
                        continue;
                      
                    }
                    else{
                          return abs(x2-x1)*abs(y2-y1);
                    }
                }
            }
        }

        return ans;

    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int ans=-1;
        int n=points.size();
        if(n<4) return ans;
        sort(points.begin(),points.end());

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                if(x1!=x2) continue;
                ans=max(ans,findThirdAndFourth(points,x1,y1,y2));
            }
        }

        return ans;
    }
};