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


// Another Easy:
// Balanced check if its min == max

class Solution {
public:
    bool isBalance(unordered_map<char, int>&m){  // check that substr is balanced or not (min==max)
        int mn = INT_MAX;
        int mx = 0;
        for(auto &p:m){
            mn = min(mn, p.second);
            mx = max(mx, p.second);
        }
        return mn == mx;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int>m;
            for(int j=i; j<n; j++){
                m[s[j]]++;
                if(isBalance(m)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
