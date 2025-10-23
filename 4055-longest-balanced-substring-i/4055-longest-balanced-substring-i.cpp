class Solution {
public:
    bool isBalance(map<char,int>&m, int target){
        for(auto &p:m){
            if(p.second!=0 and p.second!=target) return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            map<char, int>m;
            for(int j=i; j<n; j++){
                m[s[j]]++;
                if(isBalance(m, m[s[j]])){  //m[s[j]] -> the current freq of the most recently added char
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};