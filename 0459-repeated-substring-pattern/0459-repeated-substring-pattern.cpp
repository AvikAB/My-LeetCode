class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n<=1) return false;
        string t = s+s;
        string t_sub = t.substr(1, 2*n-2);  // remove the first & last char of t string
        /*If the 's' string exist in the t's substring, then it made by repeating a smaller substr, otherwise not*/
        return t_sub.find(s) != string::npos;
    }
};