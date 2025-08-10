class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());
        for(int i=0; i<31; i++){
            int power = 1<<i;  // 2^i
            string temp = to_string(power);
            sort(temp.begin(), temp.end());
            if(num==temp) return true;
        }
        return false;
    }
};

/*
First generate all power of 2 till 1e9 then we want to check if existing n is any permutation of power of 2.
*/