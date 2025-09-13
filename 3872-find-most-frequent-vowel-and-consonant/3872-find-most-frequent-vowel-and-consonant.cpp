class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowel;
        unordered_map<char, int> conso;
        for(char c:s){
            if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') vowel[c]++;
            else conso[c]++;
        }
        int mxVow = 0, mxConso = 0;
        for(auto &av:vowel){
            mxVow = max(mxVow, av.second);
        }
        for(auto &av:conso){
            mxConso = max(mxConso, av.second);
        }
        return mxVow+mxConso;
    }
};