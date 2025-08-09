class Solution {
public:
    bool isHappy(int n) {
        if(n==1 or n==7) return true;
        else if(n<10) return false;
        else {
            int sum = 0;
            while(n){
                int ld = n%10;
                sum += (ld*ld);
                n /= 10;
            }
            return isHappy(sum);
        }
    }
};