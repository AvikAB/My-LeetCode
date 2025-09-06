class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        //No overlapping case:
        while(i<n and intervals[i][1] < newInterval[0]){   // compare ending point of intervals to starting point of newInterval
            res.push_back(intervals[i]);
            i++;
        }

        // Overlapping case
        while(i<n and intervals[i][0] <= newInterval[1]){   // compare starting point of intervals to ending point of NewIntervals
            // find the range
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        //No overlapping of intervals after newInterval being merged
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};