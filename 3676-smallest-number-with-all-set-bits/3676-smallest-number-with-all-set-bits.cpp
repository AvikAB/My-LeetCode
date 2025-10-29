class Solution {
public:
    int smallestNumber(int n) {
        long long int x = 1;
        while(1){
            int val = (1<<x)-1;
            if(val>=n) return val;
            x++;
        }
    }
};