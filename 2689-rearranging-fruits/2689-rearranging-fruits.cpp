class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int>mp;
        int mnEle = INT_MAX;
        for(auto &av:basket1){
            mp[av]++;
            mnEle = min(mnEle, av);
        }
        for(auto &av:basket2){
            mp[av]--;
            mnEle = min(mnEle, av);
        }
        vector<int>final;
        for(auto &av:mp){
            int cost = av.first;
            int cnt = av.second;
            if(cnt==0) continue;  // they are in equal in both
            if(cnt%2!=0) return -1;
            for(int c=1; c<=abs(cnt)/2; c++){
                final.push_back(cost);
            }
        }
        sort(final.begin(), final.end());
        long long res = 0;
        for(int i=0; i<final.size()/2; i++){
            res += min(final[i], mnEle*2);
        }
        return res;
    }
};