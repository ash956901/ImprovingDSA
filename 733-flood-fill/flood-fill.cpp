class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>  q;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();
        int startc=image[sr][sc];
         if(image[sr][sc]==color) return image;
        image[sr][sc]=color;
        while(!q.empty()){
            
           
                auto [i,j]=q.front();
            q.pop();
               
            if(i-1>=0 && image[i-1][j]==startc){
                image[i-1][j]=color;
                q.push({i-1,j});
            }

            if(i+1<n && image[i+1][j]==startc){
                 image[i+1][j]=color;
                q.push({i+1,j});
            }

            if(j-1>=0 && image[i][j-1]==startc){
                 image[i][j-1]=color;
                q.push({i,j-1});
            }

            if(j+1<m && image[i][j+1]==startc){
                 image[i][j+1]=color;
                q.push({i,j+1});
            }
            
            
        }

        return image;
    }
};