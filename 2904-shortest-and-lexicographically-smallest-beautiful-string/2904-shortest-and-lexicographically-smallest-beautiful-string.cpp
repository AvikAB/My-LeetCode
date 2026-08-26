class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // optimized
        int n = s.size();
        string ans = "";
        int cnt1 = 0;
        int l = 0, r = 0;
        while(r<n){
            if(s[r]=='1') cnt1++;
            if(cnt1==k){
                while(l<n and cnt1==k){   // shrink from left for small len
                    string curr = s.substr(l, r-l+1);
                    if(ans=="" or curr.size()<ans.size()) ans = curr;
                    else if(ans.size()==curr.size()) ans = min(ans, curr);
                    if(s[l]=='1') cnt1--;
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};