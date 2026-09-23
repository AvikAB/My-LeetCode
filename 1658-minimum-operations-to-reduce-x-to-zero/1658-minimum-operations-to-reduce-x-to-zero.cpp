class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int keep = sum - x;

        if(keep<0) return -1;

        // longest subarray having sum exactly keep
        int l = 0, curr_w = 0;
        int len = -1;
        for(int r=0; r<n; r++){
            curr_w += nums[r];
            while(curr_w > keep){
                curr_w -= nums[l];
                l++;
            }
            if(curr_w==keep){
                len = max(len, r-l+1);
            }
        }
        return (len==-1) ? -1 : (n-len);
    }
};