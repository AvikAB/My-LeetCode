class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for(char c:s){
            if(!ans.empty() and c=='*') ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};