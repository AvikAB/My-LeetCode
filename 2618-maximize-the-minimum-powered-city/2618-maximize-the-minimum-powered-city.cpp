class Solution {
public:
    #define ll long long int
    bool check(ll mid, vector<ll>& diff, int r, int k, int n) {
        vector<ll> tempDiff = diff;
        ll cumSum = 0; //it will give power of a city at any point of time
        for(int i=0; i<n; i++){
            cumSum += tempDiff[i];
            if(cumSum < mid){
                ll need = mid-cumSum;
                if(need>k) return false;
                k -= need;
                cumSum += need; //gredily I had chosen to add station on the city which can cover more range
                //i......X.....i+2*r
                if(i+2*r+1<n) tempDiff[i+2*r+1] -= need; //applying difference array technique
            }
        }
        return true;
    }

    ll maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> diff(n, 0);
        for(int i=0; i<n; i++) {
            diff[max(0, i-r)] += stations[i];
            if(i+r+1<n) diff[i+r+1] -= stations[i];
        }
        ll lo = *min_element(begin(stations), end(stations));
        ll hi = accumulate(begin(stations), end(stations), 0LL) + k;
        ll result = 0;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            if(check(mid, diff, r, k, n)) {
                result = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        return result;
    }
};