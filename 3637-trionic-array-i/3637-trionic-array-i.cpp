class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        // increasing
        while(i+1<n and nums[i]<nums[i+1]) i++;
        if(i==0 or i==n-1) return false;  // only inc is present

        // decreasing
        while(i+1<n and nums[i]>nums[i+1]) i++;
        if(i==n-1) return false;  // only inc & dec are present

        // increasing
        while(i+1<n and nums[i]<nums[i+1]) i++;

        return i==n-1;
    }
};