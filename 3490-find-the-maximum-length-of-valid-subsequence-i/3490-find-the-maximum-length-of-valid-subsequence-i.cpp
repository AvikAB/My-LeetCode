class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddCnt = 0;
        int evenCnt = 0;
        for(int &av:nums){
            if(av%2==0) evenCnt++;
            else oddCnt++;
        }
        int alternating = 1;
        int parity = nums[0]%2;
        for(int i=1; i<nums.size(); i++){
            int currParity = nums[i]%2;
            if(currParity!=parity) alternating++;
            parity = currParity;
        }
        return max({oddCnt, evenCnt, alternating});
    }
};