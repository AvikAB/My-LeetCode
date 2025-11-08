class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        vector<long long>f(31,0);
        // f[i] = Num of ops to convert a num (having only ith bit set) to 0
        f[0] = 1;  // for the 0th bit, it always taken 1 step
        for(int i=1; i<=30; i++){
            f[i] = 2*f[i-1]+1;
        }
        int res = 0;
        int sign = 1;
        for(int i=30; i>=0; i--){   // left to right traverse
            int ith_bit = ((1<<i) & n);  // check the ith bit is set or not
            if(ith_bit==0) continue;  // skip if ith_bit is unset
            // alternating sum here
            if(sign>0) res += f[i];
            else res -= f[i];
            sign *= (-1);
        }
        return res;
    }
};


/*
    Create a vector named 'f', where we put num of ops to convert a num to 0, when the bit is set. Here we used a formula 2*f(i-1)+1. Now check in given num, where the set bits are present. Pick there f(set_bit) and do alternating sum.
*/