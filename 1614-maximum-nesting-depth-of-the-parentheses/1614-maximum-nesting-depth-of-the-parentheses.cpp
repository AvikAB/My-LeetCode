class Solution {
public:
    int maxDepth(string s) {
        int dep = 0, mx = 0;
        for(char c:s){
            if(c=='('){
                dep++;
                mx = max(mx, dep);
            } else if(c==')') dep--;
        }
        return mx;
    }
};