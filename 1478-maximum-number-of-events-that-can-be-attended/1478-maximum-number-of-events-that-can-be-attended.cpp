class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int day = events[0][0];   // events[i][0] -> starting day, events[i][1] -> ending day
        int ans = 0;
        int i = 0;
        while(i<n or !minHeap.empty()){
            while(i<n and events[i][0]==day){  // if starting day is matching with current day then push it in minHeap (push only end day)
                minHeap.push(events[i][1]);
                i++;
            }

            if(!minHeap.empty()){
                minHeap.pop();   // event attended on this day
                ans++;
            }
            day++;
            //skip those events whose endDay < current day
            while(!minHeap.empty() and minHeap.top()<day){
                minHeap.pop();
            }
        }
        return ans;
    }
};