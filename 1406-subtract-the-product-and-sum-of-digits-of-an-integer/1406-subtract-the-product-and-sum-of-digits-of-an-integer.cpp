class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        while(n){
            int ld = n%10;
            prod *= ld;
            sum += ld;
            n /= 10;
        }
        return prod-sum;
    }
};