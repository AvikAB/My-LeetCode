class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 and 1162261467%n==0;
    }
};

/*
    Mathematical Observation:
    1. The largest power of 3 within the 32-bit integer range is (3^19 = 1162261467).
    2.If (n) is a power of three, it must divide (1162261467) without leaving a remainder.
*/