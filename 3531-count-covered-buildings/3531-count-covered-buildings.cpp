class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> xtoy;
        unordered_map<int, vector<int>> ytox;  
        for (const auto &av: buildings) {
            int x = av[0];
            int y = av[1];
            xtoy[x].push_back(y);
            ytox[y].push_back(x);
        }
        for (auto &av: xtoy){
            sort(av.second.begin(), av.second.end());
        }
        for (auto &av: ytox) {
            sort(av.second.begin(), av.second.end());
        }
        int cnt = 0;
        for (const auto &av: buildings) {
            int x = av[0];
            int y = av[1];
            bool l = false;
            bool r = false;
            bool u = false;
            bool d = false;
            if(xtoy.find(x) != xtoy.end()){
                const auto &ys = xtoy[x];
                auto it = lower_bound(ys.begin(), ys.end(), y);
                if(it != ys.begin()) l = true;
            }
            if(xtoy.find(x) != xtoy.end()){
                const auto &ys = xtoy[x];
                auto it = upper_bound(ys.begin(), ys.end(), y);
                if(it != ys.end()) r = true;
            }
            if(ytox.find(y) != ytox.end()){
                const auto &xs = ytox[y];
                auto it = lower_bound(xs.begin(), xs.end(), x);
                if(it != xs.begin()) u = true;
            }
            if(ytox.find(y) != ytox.end()){
                const auto &xs = ytox[y];
                auto it = upper_bound(xs.begin(), xs.end(), x);
                if(it != xs.end()) d = true;
            }
            if(l and r and u and d) cnt++;
        }
        return cnt;
    }
};