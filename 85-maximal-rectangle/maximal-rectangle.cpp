class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

       
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxRect = 0;

        for (auto& row : matrix) {
            for (int i = 0; i < n; ++i) {
            
                heights[i] = row[i] == '1' ? heights[i] + 1 : 0;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};
