class Solution {
public:
    int trap(vector<int>& height) {
        int count=0;
        stack<int> ng;
        for(int i=0;i<height.size();i++){
            while(!ng.empty() && height[ng.top()]<=height[i]){
                int ngTop=ng.top();
                ng.pop();

                if(!ng.empty()){
                    int h=min(height[ng.top()],height[i])-height[ngTop];

                    int width=i-(ng.top()+1);
                    count+=h*width;
                }
                
            }
            ng.push(i);
        }

        return count;
    }
};