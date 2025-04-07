class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = s.size();
        int n = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0, r=0;
        while(l<m and r<n){   // l for children(c) & r for cookies(s)
            if(g[r]<=s[l]) r++;
            l++;
        }
        return r;
    }
};