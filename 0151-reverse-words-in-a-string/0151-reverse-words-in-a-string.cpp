class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++){
            string word = "";
            while(i<n and s[i]!=' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.size()>0){  // got a valid word
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

/*
Reverse entire string first then reverse every individual word.
*/