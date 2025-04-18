class Solution {
public:
    int maxDifference(string s) {
        vector<int>cnt(26);
        for(int i=0; i<s.size(); i++){
            cnt[s[i]-'a']++;
        }
        int mxodd = 0, mneven = s.size()+1;
        for(int i=0; i<26; i++){
            if(cnt[i]%2) mxodd = max(mxodd, cnt[i]);
            else if(cnt[i]>0 and cnt[i]%2==0) mneven = min(mneven, cnt[i]); 
        }
        return mxodd - mneven;
    }
};