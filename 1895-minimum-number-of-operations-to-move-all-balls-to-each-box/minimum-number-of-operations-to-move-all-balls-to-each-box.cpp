class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);
        int score = 0, balls = 0;
        for (int i = 0; i < boxes.size(); i++) {
            ans[i] += score;
            balls += (boxes[i] - '0');
            score += balls;
        }
        
        score = 0, balls = 0;
        for (int i = boxes.size() - 1; i >= 0; i--) {
            ans[i] += score;
            balls += (boxes[i] - '0');
            score += balls;
        }
        
        return ans;
    }
};
