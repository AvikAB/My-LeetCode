class Solution {
public:
    string reverseVowels(string s) {
        vector<char>vowels;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                vowels.push_back(s[i]);
            }
        }
        int i=0, j=0;
        while(i<s.size() and j<vowels.size()){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                s[i] = vowels[j];
                j++;
            }
            i++;
        }
        return s;
    }
};