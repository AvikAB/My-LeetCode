class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(char av:s){
            if(av!='*' and av!='#' and av!='%') ans.push_back(av);
            else if(av=='*' and !ans.empty()) ans.pop_back();
            else if(av=='#') ans += ans;
            else if(av=='%') reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};