class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

       
        for (int i = 0; i <= n; ++i) {
            int curr = (i < n ? heights[i] : 0);

            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()]; 
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                int width = i - left;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
