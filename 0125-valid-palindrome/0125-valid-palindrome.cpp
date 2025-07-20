class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i<=j){
            if(isalnum(s[i])==false){   // s[i] is not alphanumeric(spaces,# etc) then skip it
                i++;
                continue;
            }
            if(isalnum(s[j])==false){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++, j--;  // do it every time 
        }
        return true;
    }
};