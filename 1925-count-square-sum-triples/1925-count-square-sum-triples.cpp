class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                int sum = a*a + b*b;
                int c = sqrt(sum);
                if(c<=n and c*c==sum) cnt++;  // check the bound & perfect square
            }
        }
        return cnt;
    }
};