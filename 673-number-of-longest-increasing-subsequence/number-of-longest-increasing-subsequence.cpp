class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> length(n, 1), count(n, 1);
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && (length[j] + 1 > length[i])) {
               
                    length[i] = length[j] + 1;
                    count[i] = count[j];  
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j]; 
                }
            }
        
        maxLen = max(maxLen, length[i]);
    }

    int totalCount = 0;
    for (int i = 0; i < n; i++) {
        if (length[i] == maxLen) {
            totalCount += count[i];
        }
    }
    return totalCount;
}



};