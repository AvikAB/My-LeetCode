class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.emplace_back(startTime[i], endTime[i]);
        }
        sort(v.begin(), v.end());
        vector<int>gp;
        gp.push_back(v[0].first);
        for(int i=1; i<n; i++){
            gp.push_back(v[i].first - v[i-1].second);
        }
        gp.push_back(eventTime-v[n-1].second);
        int maxFree = 0;
        int wsum = 0;
        
        for(int i=0; i<=k; i++){
            wsum += gp[i];
        }
        maxFree = wsum;
        for(int i=k+1; i<gp.size(); i++){
            wsum += gp[i] - gp[i-(k+1)];
            maxFree = max(maxFree, wsum);
        }
        return maxFree;
    }
};;