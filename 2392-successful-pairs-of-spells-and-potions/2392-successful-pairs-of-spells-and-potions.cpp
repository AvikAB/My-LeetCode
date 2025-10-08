class Solution {
public:
    #define ll long long
    ll binSearch(vector<int>&potions, ll sp, ll success){
        ll lo = 0, hi = potions.size()-1;
        ll ans = -1;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            if(1LL*potions[mid]*sp >= success){
                ans = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ll idx = binSearch(potions, spells[i], success);
            if(idx!=-1) ans[i] = potions.size()-idx;
        }
        return ans;
    }
};