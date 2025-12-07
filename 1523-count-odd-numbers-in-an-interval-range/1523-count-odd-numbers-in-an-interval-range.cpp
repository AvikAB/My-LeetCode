class Solution {
public:
    int countOdds(int low, int high) {
        return ((high+1)/2) - (low/2);
    }
};

/*
Alternative: total = (high-low)+1.
    if low is odd -> (total+1)/2.
    if low is even -> total/2.
*/