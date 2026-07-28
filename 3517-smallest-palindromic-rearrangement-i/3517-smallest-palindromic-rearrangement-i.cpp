class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string first_half = s.substr(0, n/2);
        sort(first_half.begin(), first_half.end());

        string middle = "";
        if(n%2==1) middle = s[n/2];
        
        string reversed_half = first_half;
        reverse(reversed_half.begin(), reversed_half.end());
        return first_half + middle + reversed_half;
    }
};