class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int>v;
        int sc = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){  // maybe new start
                v.push_back(sc);
                sc = 0;
            } else {  // ')'
                if(s[i-1]=='('){
                    sc = v.back()+1;
                } else {  // nested
                    sc = v.back() + (2*sc);
                }
                v.pop_back();
            }
        }
        return sc;
    }
};