class Solution {
public:
    // bruteforce
    bool isPalin(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int bestStart = 0, mxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(s, i, j)){
                    int len = j-i+1;
                    if(len>mxLen){
                        mxLen = len;
                        bestStart = i;
                    }
                }
            }
        }
        return s.substr(bestStart, mxLen);
    }
};