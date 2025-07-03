class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<k){
            int sz = s.size();  // size is changeable after every iteration
            for(int i=0; i<sz; i++){
                char nxtChar = 'a'+((s[i]-'a'+1)%26);
                s += nxtChar;
            }
        }
        return s[k-1];
    }
};