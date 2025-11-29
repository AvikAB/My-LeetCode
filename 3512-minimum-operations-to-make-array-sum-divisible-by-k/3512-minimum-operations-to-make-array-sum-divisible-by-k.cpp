class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto av:nums){
            sum += av;
        }
        int rem = sum%k;
        if(rem==0) return 0;
        return rem;
    }
};