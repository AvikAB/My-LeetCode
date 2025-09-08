class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            unsigned carry = (unsigned)(a&b)<<1;  // carry bits
            a = a^b;
            b = carry;
        }
        return a;
    }
};




/*
The XOR operator adding two numbers without considering the carry. The AND operator followed by a left shift (<<1) gives us the carry bits.
By repeatedly updating the sum and carry, we eventually reach the final result once the carry becomes zero.

Initialize two numbers a and b. While b (carry) is not zero:
    Compute the carry as (a & b) << 1.
    Update a as a ^ b (partial sum without carry).
    Update b as the carry.
When carry becomes zero, a holds the result of a+b.
*/