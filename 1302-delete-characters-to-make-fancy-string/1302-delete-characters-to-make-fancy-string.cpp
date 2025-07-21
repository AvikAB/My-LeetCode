class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n<=2) return s;
        string ans = "";
        for(int i=0; i<n; i++){
            char curr = s[i];
            if(ans.size()>=2 and ans[ans.size()-1]==curr and ans[ans.size()-2]==curr) continue;
            ans += curr;
        }
        return ans;
    }
};


// At least 2 chars in my ans to check for consecutive, the last char in ans is the same as current (ans[ans.size()-1]) and also the second last char in ans is also the same (ans[ans.size()-2]) then skip and put the curr in the ans.