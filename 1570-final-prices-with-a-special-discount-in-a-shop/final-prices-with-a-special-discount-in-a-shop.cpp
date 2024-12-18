class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer;

        for (auto it = prices.begin(); it != prices.end(); it++) {
            auto itt = it + 1;
            for (; itt != prices.end(); itt++) {
                if (*itt <= *it) {
                    answer.push_back(*it - *itt);
                    break;
                }
            }
            if (itt == prices.end())
                answer.push_back(*it);
        }

        return answer;
    }
};