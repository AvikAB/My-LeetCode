class Solution {
public:
    int n;
    
    bool dfs(vector<int>&arr, int i, vector<bool>&vis){
        if(i<0 or i>=n or vis[i]) return false;

        if(arr[i]==0) return true;

        vis[i] = true;

        int forward = dfs(arr, i+arr[i], vis);
        int backward = dfs(arr, i-arr[i], vis);

        return forward or backward;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool>vis(n, false);
        return dfs(arr, start, vis);
    }
};