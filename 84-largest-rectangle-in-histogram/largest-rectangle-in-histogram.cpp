class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
