class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            } else {
                if(st.empty()) return false;  // this is for if the string starts with closing brackets
                char top = st.top();
                st.pop();
                if((s[i]==')' and top!='(') or (s[i]=='}' and top!='{') or (s[i]==']' and top!='[')) return false;
            }
        }
        return st.empty();
    }
};