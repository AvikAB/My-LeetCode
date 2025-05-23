class cmp {
public:
    bool operator()(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
};


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int ans = 0;
        int freeAt = INT_MIN;
        for(int i=0; i<intervals.size(); i++){
            if(freeAt <= intervals[i][0]){
                ans++;
                freeAt = intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};