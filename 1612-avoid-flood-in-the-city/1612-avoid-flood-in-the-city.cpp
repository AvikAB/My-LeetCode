class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n, -1);
        set<int>dry;
        unordered_map<int, int> lastRain;
        for(int i=0; i<n; i++){
            if(rains[i]==0){
                dry.insert(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                if(lastRain.count(lake)){
                    int last = lastRain[lake];
                    auto it = dry.upper_bound(last);
                    if(it==dry.end()) return {};  // impossible
                    else {
                        ans[*it] = lake;
                        dry.erase(it);
                    }
                }
                lastRain[lake] = i;
            }
        }
        return ans;
    }
};