class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());   // sort on starting time
        int cnt = meetings[0][0]-1;   // num of available days from the first one
        int prev = meetings[0][1];    // ending time of 1st meeting
        
        for(int i=1; i<n; i++){
            if(meetings[i][0] > prev){
                cnt += (meetings[i][0]-prev-1);   // -1 means don't count the meeting start/end days themselves
            }
            prev = max(prev, meetings[i][1]);    // update ending time 
        }
        // if there are remaining days after count all meetings
        cnt += (days-prev);
        return cnt;
    }
};