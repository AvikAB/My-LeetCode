class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int>ans(cost.size(), 0);
        int mn = INT_MAX;
        for(int i=0; i<cost.size(); i++){
            if(cost[i]<mn) mn = cost[i];
            ans[i] = mn;
        }
        return ans;
    }
};