class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // bruteforce
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            int cnt1 = 0;
            for(int j=i; j<n; j++){
                if(s[j]=='1') cnt1++;
                if(cnt1==k){
                    string curr = s.substr(i, j-i+1);
                    if(ans=="" or curr.size()<ans.size()) ans = curr;
                    else if(curr.size()==ans.size()) ans = min(curr, ans);
                }
            }
        }
        return ans;
    }
};