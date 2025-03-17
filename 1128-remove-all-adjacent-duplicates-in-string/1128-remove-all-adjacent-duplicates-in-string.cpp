class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st;
        for(auto it: s){
            if(!st.empty()){
                if(!st.empty() and st.top()==it) st.pop();
                else st.push(it);
            }
            else st.push(it);
        }
        s.clear();
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
