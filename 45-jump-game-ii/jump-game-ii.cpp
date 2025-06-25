class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, currEnd = 0, farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                steps++;
                currEnd = farthest;
            }
        }

        return steps;
    }
};
