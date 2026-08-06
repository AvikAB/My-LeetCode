class Solution {
public:
    int product(int num){
        int pro = 1;
        while(num){
            pro *= (num%10);
            num /= 10;
        }
        return pro;
    }

    int smallestNumber(int n, int t) {
        while(product(n)%t!=0) n++;
        return n;
    }
};