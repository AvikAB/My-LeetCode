class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        int sum = 0;
        int cnt = 0;
        int digits[10];
        while(n){
            int dig = n%10;
            if(dig!=0){
                digits[cnt++] = dig;
                sum += dig;
            }
            n /= 10;
        }

        long long x = 0;
        for(int i=cnt-1; i>=0; i--){
            x = x*10+digits[i];
        }
        return x*sum;
    }
};