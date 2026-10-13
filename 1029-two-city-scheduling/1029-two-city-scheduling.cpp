class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), [](const vector<int>&x, const vector<int>&y){
            return (x[0]-x[1]) < (y[0]-y[1]);
        });
        int ans = 0;
        for(int i=0; i<n/2; i++){   // first n/2 go to city A
            ans += costs[i][0];
        }
        for(int i=n/2; i<n; i++){   // rest go to city B
            ans += costs[i][1];
        }
        return ans;
    }
};