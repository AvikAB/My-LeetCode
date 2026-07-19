class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int>lastIdx(26);
        vector<bool>seen(26, false);
        for(int i=0; i<s.size(); i++){
            lastIdx[s[i]-'a'] = i;
        }
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            int idx = c-'a';
            if(seen[idx]==true) continue;  // skip, its already taken

            while(!ans.empty() and ans.back()>c and lastIdx[ans.back()-'a']>i){
                seen[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            seen[idx] = true;
        }
        return ans;
    }
};