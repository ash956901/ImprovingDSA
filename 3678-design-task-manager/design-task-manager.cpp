class TaskManager {
    priority_queue<vector<int>> q;
    unordered_map<int, vector<int>> taskMap;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
            {
               
                int userId = tasks[i][0], taskId = tasks[i][1], priority = tasks[i][2];
                q.push({priority, taskId, userId});
                taskMap[taskId] = {priority, userId};
            }
    }
    
    void add(int userId, int taskId, int priority) {
        q.push({priority,taskId,userId});
        taskMap[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
      
        vector<int> vt=taskMap[taskId];
        int userId = vt[1];
        taskMap[taskId] = {newPriority, userId};
        q.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {
        while (!q.empty()) {
            vector<int> top = q.top();
            int priority = top[0], taskId = top[1], userId = top[2];
            if (taskMap.find(taskId) != taskMap.end() && 
                taskMap[taskId][0] == priority) {
                q.pop();
                taskMap.erase(taskId);
                return userId;
            }
            q.pop(); 
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
