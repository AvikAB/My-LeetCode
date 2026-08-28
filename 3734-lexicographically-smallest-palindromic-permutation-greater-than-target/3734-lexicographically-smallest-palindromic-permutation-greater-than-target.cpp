class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int half = n/2;
        vector<int> f(26, 0);
        
        for(char c:s){
            f[c-'a']++;
        }

        int odd = -1;
        for(int i=0; i<26; i++){
            if(f[i]%2==1){
                if(odd!=-1) return "";
                odd = i;
            }
        }

        int pos = 0;
        while(pos<half and f[target[pos]-'a']>1){
            f[target[pos]-'a'] -= 2;
            pos++;
        }

        if(pos==half){
            string ans = target.substr(0, half);
            string rev = ans;
            reverse(rev.begin(), rev.end());  
            if(n%2==1) ans.push_back(char('a'+odd));
            ans += rev;

            if (ans>target) return ans;
        }

        int start = (half==pos) ? half-1 : pos;

        for(int i=start; i>=0; i--){
            if(i<pos){
                f[target[i]-'a'] += 2;
            }

            for(int k=0; k<26; k++){
                if(f[k]>1 and k>(target[i]-'a')){
                    string ans = target.substr(0, i);
                    ans.push_back(char('a'+k));
                    f[k] -= 2;

                    for(int x=0; x<26; x++){
                        while(f[x]>1){
                            ans.push_back(char('a'+x));
                            f[x] -= 2;
                        }
                    }

                    string rev = ans;
                    reverse(rev.begin(), rev.end());
                    ans += rev;

                    if(n%2==1){
                        ans.insert(n/2, 1, char('a'+odd));
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};