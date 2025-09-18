class TaskManager {
public:
    unordered_map<int,pair<int,int> > mp;
    priority_queue<pair<pair<int,int>,int>> pq; 
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& v:tasks){
            mp[v[1]].first=v[2];
            mp[v[1]].second=v[0];
            pq.push({{v[2],v[1]},v[0]});
        }
    
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId].first=priority;
        mp[taskId].second=userId;
        pq.push({{priority,taskId},userId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId=mp[taskId].second;
        mp[taskId].first=newPriority;
        pq.push({{newPriority,taskId},userId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
    while(!pq.empty()){
        auto p=pq.top();
        int pr=p.first.first;
        int taskId=p.first.second;
        int uId=p.second;
        if(mp.find(taskId)==mp.end()){
            pq.pop();
            continue;
        }
        int realPr = mp[taskId].first;
        

        
        if(realPr==pr){
            pq.pop();
            mp.erase(taskId);
            return uId;
        } else {
            pq.pop();
            continue;
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