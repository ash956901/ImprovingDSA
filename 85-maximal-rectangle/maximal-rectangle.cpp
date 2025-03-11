class Solution {
public:
    int lra(vector<int>& heights) {
        int area = 0;
        stack<int> ng;
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {
            while (!ng.empty() && heights[ng.top()] > heights[i]) {
                int topIndex = ng.top();
                ng.pop();
                int width = ng.empty() ? i : i - ng.top() - 1;
                area = max(area, heights[topIndex] * width);
            }
            ng.push(i);
        }
        
        while (!ng.empty()) {
            int topIndex = ng.top();
            ng.pop();
            int width = ng.empty() ? n : n - ng.top() - 1;
            area = max(area, heights[topIndex] * width);
        }
        
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(),0);
        //allot first row values
        int n=matrix.size();
        for(int j=0;j<matrix[0].size();j++){
            heights[j]=matrix[n-1][j]-'0';
        }
       
      
        int ans=lra(heights);
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]!='0'){
                    heights[j] += (matrix[i][j]-'0');
                   
                }
                else{
                  
                    heights[j]=0;
                }
            }
            
           
            ans=max(ans,lra(heights));
        }
        return ans;
    }
};
