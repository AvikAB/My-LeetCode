class Solution {
public:
    bool check(int n){
        while(n){
            int dig = n%10;
            if(dig==0) return false;
            n /= 10;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=n-1; i++){
            if(check(i) and check(n-i)) return {i, n-i};
        }
        return {};
    }
};