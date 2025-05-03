class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];   // first string of the strs vector
        string last = strs[n-1];  // last string of the strs vector
        for(int i=0; i<min(first.size(), last.size()); i++){
            if(first[i]==last[i]) ans += first[i];   // adding common chars
            else break;
        }
        return ans;
    }
};