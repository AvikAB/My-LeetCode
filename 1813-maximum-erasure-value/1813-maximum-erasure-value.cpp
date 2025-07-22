class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> um;
        int left = 0, currSum = 0, mxSum = 0;
        for(int right=0; right<nums.size(); right++){
            while(um.find(nums[right]) != um.end()){   // duplicate found
                currSum -= nums[left];
                um.erase(nums[left]);
                left++;
            }
            um.insert(nums[right]);
            currSum += nums[right];
            mxSum = max(currSum, mxSum);
        }
        return mxSum;
    }
};