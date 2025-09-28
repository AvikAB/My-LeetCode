class Solution {
public:
    #define ll long long
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        ll p = 1;
        while(n){
            int ld = n%10;
            if(ld!=0) ans.push_back(ld*p);
            n /= 10;
            p *= 10;
        }
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};