class Solution {
public:
    bool isVow(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }

    int countVowelSubstrings(string word) {
        int ans = 0;
        unordered_map<char, int> cnt;
        for(int i=0; i<word.size(); i++){
            cnt.clear();   // start a new substring scan from position 'i'
            for(int j=i; j<word.size() and isVow(word[j]); j++){
                cnt[word[j]]++;
                if(cnt.size()==5) ans++;
            }
        }
        return ans;
    }
};