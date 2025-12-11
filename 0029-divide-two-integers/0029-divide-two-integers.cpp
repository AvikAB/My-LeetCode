class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor == -1) return INT_MAX;
        if(divisor==1) return dividend;
        if(divisor==-1) return -dividend;
        bool neg = (dividend<0) != (divisor<0);  // if both are not same then its neg
        long a = labs(dividend);
        long b = labs(divisor);
        long ans = 0;
        while(a>=b){
            long temp = b;
            long cnt = 1;
            while((temp<<1)<a){
                temp <<= 1; // temp = temp*2
                cnt <<= 1; // cnt = cnt*2
            }
            a -= temp;  // subtract the big
            ans += cnt;  // add how many times we substract
        }
        if(neg) ans = -ans;
        return ans;
    }
};