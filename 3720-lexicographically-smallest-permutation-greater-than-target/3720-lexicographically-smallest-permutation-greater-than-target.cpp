class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int>freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        for(int pos=n-1; pos>=0; pos--){
            vector<int>temp = freq;
            bool possible = true;
            for(int i=0; i<pos; i++){
                int ch = target[i]-'a';
                if(temp[ch]==0){
                    possible = false;
                    break;
                }
                temp[ch]--;
            }
            if(possible==false) continue;

            // find smallest char, greater than target[pos]
            int ch = target[pos] - 'a';
            int big = -1;
            for(int j=ch+1; j<26; j++){
                if(temp[j]>0){
                    big = j;
                    break;
                }
            }
            if(big==-1) continue;
            string ans = "";

            // add the same prefix as target
            for(int i=0; i<pos; i++){
                ans += target[i];
            }

            // add the smallest possible bigger char
            ans += char('a'+big);
            temp[big]--;

            // add remaining char in sorted order
            for(int j=0; j<26; j++){
                while(temp[j]>0){
                    ans += char('a'+j);
                    temp[j]--;
                }
            }
            return ans;
        }
        return "";
    }
};