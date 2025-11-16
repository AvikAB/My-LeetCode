class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int cnt = 0;
        int ans = 0;
        int mod = 1e9+7;
        for(char av:s){
            if(av=='1'){
                cnt++;
                ans = (ans+cnt) % mod;
            }
            else cnt = 0;
        }
        return ans;
    }
};