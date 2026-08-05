class Solution {
public:
    void dfs(int node, vector<int>&sus, vector<int>adj[]){
        sus[node] = 1;
        for(auto child:adj[node]){
            if(sus[child]==0) dfs(child, sus, adj);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(int i=0; i<invocations.size(); i++){
            int a = invocations[i][0];
            int b = invocations[i][1];
            adj[a].push_back(b);
        }

        vector<int>sus(n, 0);
        dfs(k, sus, adj);
        vector<int>ans;

        for(int i=0; i<invocations.size(); i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            // if its find the non-sus to sus then return all nodes
            if(sus[u]==0 and sus[v]==1){
                for(int j=0; j<n; j++){
                    ans.push_back(j);
                }
                return ans;
            }
        }
        
        // return all non-sus if there no connection
        for(int i=0; i<n; i++){
            if(sus[i]==0) ans.push_back(i);
        }
        return ans;
    }
};