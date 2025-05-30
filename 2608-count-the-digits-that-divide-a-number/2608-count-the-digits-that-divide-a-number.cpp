class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while(num){
            int ld = num%10;
            if(n%ld==0) ans++;
            num/=10;
        }
        return ans;
    }
};