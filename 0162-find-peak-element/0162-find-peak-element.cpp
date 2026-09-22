class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[mid+1]){  // mid can be peak, now check from left side
                r = mid;
            } else {  // n[mid]<n[mid+1] then mid can't be peak, mid+1 can be peak, so check from right side
                l = mid+1;
            }
        }
        return l;
    }
};