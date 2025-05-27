class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totSum = n*(n+1)/2;
        int divSum = m*(n/m)*(n/m+1);
        return totSum - divSum;
    }
};