class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1) return 1;
        int num = 0;
        for(int i=1; i<=k; i++){
            num = (num*10+1)%k;
            if(num==0) return i;
        }
        return -1;
    }
};

/* Just think about the remainder. let, k = 3. So, We need 1%3 = 1, 11%3 = 2, 111%3 = 0.
We can do it with their remainder.1%3 = 1, we can use this remainder '1'. 1*10+1 = 11, 11%3 = 2,
It gives the same. Now, 2*10+1 = 21%3 = 0. It also gives the same.
Here, i will give the length of the number which is divisible by k.
*/