class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>mxSuff(n+1, 0);
        int i = n-1, j = m-1;
        while(i>=0 and j>=0){
            if(word1[i]==word2[j]){
                mxSuff[i] = m-j;
                i--, j--;
            } else {
                i--;
            }
        }
        for(int i=n-2; i>=0; i--){
            mxSuff[i] = max(mxSuff[i], mxSuff[i+1]);
        }

        vector<int>ans;
        i = 0, j = 0;
        int op = 0;
        while(i<n and j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                i++, j++;
            } else {
                int remLen = m-j-1;
                if(mxSuff[i+1]>=remLen and op==0){
                    ans.push_back(i);
                    i++, j++;
                    op = 1;
                } else i++;
            }
        }

        if(ans.size()==m) return ans;
        else return {};
    }
};