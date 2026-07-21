class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='1') one++;
        }
        string t = "1"+s+"1";
        vector<pair<char,int>>v;
        for(int i=0; i<t.size(); ){
            int j = i;
            while(j<t.size() and t[j]==t[i]) j++;
            v.push_back({t[i], j-i});
            i = j;
        }
        int ans = one;
        for(int i=1; i<v.size()-1; i++){
            if(v[i].first=='1' and v[i-1].first=='0' and v[i+1].first=='0'){
                int gain = v[i-1].second + v[i+1].second;
                ans = max(ans, one+gain);
            }
        }
        return ans;
    }
};