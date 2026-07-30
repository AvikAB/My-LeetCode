class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int>cnt(26, 0);
        for(int i=0; i<word.size(); i++){
            cnt[word[i]-'a']++;
        }
        sort(cnt.rbegin(), cnt.rend());
        for(int i=0; i<26; i++){
            int press = i/8 + 1;
            ans += (cnt[i]*press);
        }
        return ans;
    }
};