class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(auto av:p){
            mp[av]++;
        }
        int cnt = mp.size();
        int k = p.size();
        int i = 0, j = 0;
        while(j<s.size()){
            // add s[j] to window
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }

            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(cnt==0) ans.push_back(i);
                // remove s[i] from window
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) cnt++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};