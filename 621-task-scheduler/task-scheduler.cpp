class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }
        
        priority_queue<int> pq;
        for (auto [task, count] : freq) {
            pq.push(count);
        }
        
        queue<pair<int, int>> cooldown;  // {count, available time}
        int time = 0;
        
        while (!pq.empty() || !cooldown.empty()) {
            time++;
            
            // If the most frequent task is available, process it
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                count--;
                
                if (count > 0) {
                    cooldown.push({count, time + n}); // Reinsert after cooldown
                }
            }

            // If a task's cooldown period is over, push it back into the heap
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        
        return time;
    }
};
