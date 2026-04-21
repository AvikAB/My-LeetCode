class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        vector<int> freq(10, 0);
        for(auto av:nums){
            int n = av;
            while(n){
                int dig = n%10;
                n /= 10;
                freq[dig]++;
            }
        }
        return freq[digit];
    }
};