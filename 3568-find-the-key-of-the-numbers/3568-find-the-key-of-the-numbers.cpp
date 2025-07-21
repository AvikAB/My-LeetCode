class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0, pow10 = 1;
        while(num1 and num2 and num3){
            int a = num1%10, b = num2%10, c = num3%10;
            int mn = min({a,b,c});
            key += (mn*pow10);
            pow10 *= 10;
            num1 /= 10, num2 /= 10, num3 /= 10;
        }
        return key;
    }
};