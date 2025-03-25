class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3) return 0;
        int cnt = 0;
        for(int i=0; i<=s.size()-3; i++){    // sliding window
            unordered_set<char>us = {s[i], s[i+1], s[i+2]};  //unordered_set for no sorting elements
            if(us.size()==3) cnt++;
        }
        return cnt;
    }
};