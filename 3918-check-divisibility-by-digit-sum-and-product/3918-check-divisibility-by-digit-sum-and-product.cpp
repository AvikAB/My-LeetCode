class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int temp = n;
        while(temp){
            int ld = temp%10;
            sum += ld;
            prod *= ld;
            temp /= 10;
        }
        int tot = sum+prod;
        if(n%tot==0) return true;
        return false;
    }
};