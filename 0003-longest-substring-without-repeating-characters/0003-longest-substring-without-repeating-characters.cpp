class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>vis(256,0);
        int l=0, r=0, len=0;
        while(r<s.size()){
            while(vis[s[r]]){
                vis[s[l]] = 0;
                l++;
            }
            vis[s[r]] = 1;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};