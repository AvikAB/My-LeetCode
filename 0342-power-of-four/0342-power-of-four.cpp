class Solution {
public:
    bool isPowerOfFour(int n) {
        // If 'n' is 1, it is a power of four
        if(n==1) return true;
        // If 'n' is non-positive, it cannot be a power of four
        if(n<=0) return false;
        // calculate the log of 'n' with base 4
        double logBase4 = log(n)/log(4);
        //if the logBase4 is an int then its a power of 4
        return (logBase4 == (int)logBase4);
    }
};

/*
n = 4^x
n = (2∗2)^x
n = 2^x * 2^x
sqrt(n) = 2^x
log2(sqrt(n)) = x
*/