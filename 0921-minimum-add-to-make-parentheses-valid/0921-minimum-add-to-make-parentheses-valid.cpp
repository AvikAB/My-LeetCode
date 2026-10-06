class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0, insertion = 0;
        for(char c:s){
            if(c=='(') open++;
            else{  // ')'
                if(open>0) open--;  // if opening is available then pair it
                else insertion++;   // need more opening to pair
            }
        }
        return open + insertion;
    }
};