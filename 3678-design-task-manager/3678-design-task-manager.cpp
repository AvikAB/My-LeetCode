class TaskManager {
public:
    unordered_map<int, int> taskPrio;    // task -> priority
    unordered_map<int, int> taskUser;     // task -> user
    priority_queue<pair<int, int>> maxHeap;   // {priority, taskID}

    TaskManager(vector<vector<int>>& tasks) {
        for(auto task:tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority, taskId});
        taskPrio[taskId] = priority;
        taskUser[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        maxHeap.push({newPriority, taskId});
        taskPrio[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskPrio[taskId] = -1;   // don't remove, just lower priority
    }
    
    int execTop() {
        while(!maxHeap.empty()){
            auto [prio, taskId] = maxHeap.top();
            maxHeap.pop();
            if(prio == taskPrio[taskId]){   // check fresh or not, because don't remove anything from it
                taskPrio[taskId] = -1;
                return taskUser[taskId];
            }
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