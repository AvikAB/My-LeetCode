class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int cnt = 2;  // because we want manually add the first interval's mx and 2nd mx
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> mx(2, 0);

        // always choose last 2 max ele
        mx[0] = intervals[0][1]-1;
        mx[1] = intervals[0][1];

        int n = intervals.size();
        for(int i=1; i<n; i++){
            if(mx[1] < intervals[i][0]){   // non-overlap section
                cnt += 2;
                mx[0] = intervals[i][1]-1;
                mx[1] = intervals[i][1];
            } else if(mx[0] < intervals[i][0]){   // overlap section between mx and intervals
                cnt++;
                mx[0] = mx[1];
                mx[1] = intervals[i][1];
            }
        }
        return cnt;
    }
};