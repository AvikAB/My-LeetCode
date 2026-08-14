class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0, j=0;
        unordered_map<char,int>m;
        int ans = 0;
        while(j<n){
            m[s[j]]++;
            while(m[s[j]]>2){
                m[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};