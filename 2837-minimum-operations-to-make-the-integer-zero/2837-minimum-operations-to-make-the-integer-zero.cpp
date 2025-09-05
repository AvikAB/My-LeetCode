class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1; i<=60; i++){   // operations
            long long target = num1 - 1LL*i*num2;
            if(target<=0) return -1;
            long long bits = __builtin_popcountll(target);  // calc the num of set bits in target
            if(bits<=i and target>=i) return i;
        }
        return -1;
    }
};