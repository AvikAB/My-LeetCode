class Solution {
public:
    string findValidPair(string s) {
        vector<int>freq(10,0);
        for(char av: s){
            freq[av-'0']++;
        }
        for(int i=0; i<s.size()-1; i++){
            char f = s[i];
            char se = s[i+1];
            if(f!=se){
                if(freq[f-'0']==(f-'0') and freq[se-'0']==(se-'0')){
                    return string({f, se});
                }
            }
        }
        return "";
    }
};