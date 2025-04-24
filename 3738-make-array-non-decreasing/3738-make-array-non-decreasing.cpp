class Solution {
public:
    #define ll long long int
    int maximumPossibleSize(vector<int>& nums) {
        stack<pair<ll,ll>> st;
        for(int av:nums) {
            ll cmax = av;
            ll cnt = 1;
            while(!st.empty() && st.top().first>cmax){
                auto [pmax, pcnt] = st.top();
                st.pop();
                cmax = max(cmax, pmax);
                cnt += pcnt;
            }
            st.push({cmax, cnt});
        }
        return st.size();
    }
};