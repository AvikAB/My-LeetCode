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
                    auto it = dry.upper_bound(last);  // Find a dry day after that last rain
                    if(it==dry.end()) return {};  // not found thats why impossible
                    else {     //If found, dry that lake on that dry day.
                        ans[*it] = lake;
                        dry.erase(it);   // remove that day from dry
                    }
                }
                lastRain[lake] = i;  // update
            }
        }
        return ans;
    }
};