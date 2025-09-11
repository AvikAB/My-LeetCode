class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowels;
        for(char c:s){
            if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U'){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int i=0, j=0;     // i for s & j for vowels
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