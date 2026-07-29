class Solution {
public:

    long long nCr(int n, int r, int k){
        r = min(r, n-r);  // nCr == nC(n-r)
        long long res = 1;
        for(int i=1; i<=r; i++){
            res = res * (n-r+i)/i;
            if(res>=k) return k;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid = ' ';
        if(n%2==1) mid = s[n/2];

        vector<int> cnt(26, 0);
        for(int i=0; i<n; i++){
            if(n%2==1 and i==n/2) continue;  // mid will be reserved
            cnt[s[i]-'a']++;
        }

        // half freq will be used to build halfAns
        for(int i=0; i<26; i++){
            cnt[i] /= 2;
        }

        string halfAns = "";
        int half = n/2;
        for(int i=0; i<half; i++){
            bool ok = false;
            for(int j=0; j<26; j++){
                if(cnt[j]>0){
                    cnt[j]--;

                    // cnt num of ways
                    long long ways = 1;
                    int letters = 0;
                    for(int c=0; c<26; c++){
                        letters += cnt[c];
                    }

                    for(int c=0; c<26; c++){
                        if(cnt[c]>0){
                            ways *= nCr(letters, cnt[c], k);
                            letters -= cnt[c];
                        }
                        if(ways>=k) break;
                    }

                    if(ways>=k){
                        halfAns.push_back(j+'a');
                        ok = true;
                        break;
                    }

                    k -= ways;
                    cnt[j]++;
                }
            }
            if(ok==false) return "";
        }

        string rev = halfAns;
        reverse(rev.begin(), rev.end());
        if(mid!=' ') halfAns.push_back(mid);
        return halfAns+rev;
    }
};