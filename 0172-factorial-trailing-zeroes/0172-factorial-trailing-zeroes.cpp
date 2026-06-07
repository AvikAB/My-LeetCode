class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n/5>0){
            sum += (n/5);
            n /= 5;
        }
        return sum;
    }
};


/*
0 produced by 10 (2*5), 2 is almost divisible by every num, needs to check that num which is divisible by 5. because most 0 = min(2,5) pair.

n = 150, 0 will produced by: 5,10,15,20,25,50,75,...150 = 30 0s. Here also we get atleast 2 5's from: 25,50,75,125,150 = 6 0s. Also get 3 5's from: 125 = 1 0s.
So total 0s are = 30+6+1 = 37.

Multiples of 5: ⌊150/5⌋=30,each gives at least one 5
Multiples of 25: ⌊150/25⌋=6, each gives an extra 5 (beyond the first)
Multiples of 125: ⌊150/125⌋=1, gives another extra 5
*/