class Solution {
public:
    bool isPalindrome(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            else i++, j--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            string sub = "";
            for(int j=i; j<n; j++){
                sub += s[j];
                if(isPalindrome(sub)) cnt++;
            }
        }
        return cnt;
    }
};