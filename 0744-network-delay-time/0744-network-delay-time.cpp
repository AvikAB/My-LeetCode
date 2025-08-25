class Solution {
public:
    #define ll long long
    const ll INF = 1e9+10;

    int dijkstra(ll source, ll n, vector<vector<pair<ll,ll>>> &adjList){
        vector<ll> vis(n+1, 0);
        vector<ll> dist(n+1, INF);
        set<pair<ll,ll>> st;
        st.insert({0, source});
        dist[source] = 0;

        while(!st.empty()){
            auto node = *st.begin();
            ll v = node.second;
            ll v_dist = node.first;
            st.erase(st.begin());
            if(vis[v]) continue;
            vis[v] = 1;
            for(auto &child : adjList[v]){
                ll child_v = child.first;
                ll wt = child.second;
                if(dist[v] + wt < dist[child_v]){
                    dist[child_v] = dist[v] + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }

        ll ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<ll,ll>>> adjList(n+1);
        for(auto &av : times){
            adjList[av[0]].push_back({av[1], av[2]});
        }
        return dijkstra(k, n, adjList);
    }
};
