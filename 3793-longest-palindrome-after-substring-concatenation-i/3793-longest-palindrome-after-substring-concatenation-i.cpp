class Solution {
#define ll long long int
public:
    bool isPalindrome(const string& str) {
        return equal(str.begin(), str.begin()+str.size()/2, str.rbegin());
    }
    int longestPalindrome(string s, string t) {
        ll mxLen = 1;
        ll n = s.size(), m = t.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string a = s.substr(i, j-i+1);
                for(int x=0; x<m; x++){
                    for(int y=x; y<m; y++){
                        string b = t.substr(x, y-x+1);
                        string con1 = a+b;
                        if(isPalindrome(con1)) mxLen = max(mxLen, (ll)con1.size());
                    }
                }
            }
        }
        for(int i=0;i<n; i++){
            for(int j=i; j<n; j++){
                string sub = s.substr(i, j-i+1);
                if(isPalindrome(sub)) mxLen = max(mxLen, (ll)sub.size());
            }
        }
        for(int i=0;i<m; i++){
            for(int j=i; j<m; j++){
                string sub = t.substr(i, j-i+1);
                if(isPalindrome(sub)) mxLen = max(mxLen, (ll)sub.size());
            }
        }
        return mxLen;
    }
};