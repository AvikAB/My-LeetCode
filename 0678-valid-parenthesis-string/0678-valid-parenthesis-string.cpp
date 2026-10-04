class Solution {
public:
    bool checkValidString(string s) {
        // left traversal (treat '*' as '(')
        int open = 0;
        for(char c:s){
            if(c==')') open--;
            else open++;   // '(' or '*'
            if(open<0) return false;
        }

        // right traversal ('*' as ')')
        int close = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='(') close--;
            else close++;  // ')' or '*'
            if(close<0) return false;
        }
        return true;
    }
};