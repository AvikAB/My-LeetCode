class Solution {
public:
    // Two Pointers
    int n;
    string expand_from_center(const string &s, int l, int r){
        // starting from center, if they are equal then expand from both
        while(l>=0 and r<n and s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        n = s.size();
        if(n==0) return "";
        string mx = s.substr(0,1);
        for(int i=0; i<n; i++){
            string odd = expand_from_center(s, i, i);
            string even = expand_from_center(s, i, i+1);
            if(odd.size()>mx.size()) mx = odd;
            if(even.size()>mx.size()) mx = even;
        }
        return mx;
    }
};