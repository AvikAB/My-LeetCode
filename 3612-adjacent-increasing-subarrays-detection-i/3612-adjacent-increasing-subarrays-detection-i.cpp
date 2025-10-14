class Solution {
public:
    bool isStrictlyInc(vector<int>&nums, int start, int k){  // checking strictly increasing or not
        for(int i=start; i<start+k-1; i++){
            if(nums[i] >= nums[i+1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2*k) return false;
        if(k==1) return true;   //1 ele is always true for every ops
        for(int i=0; i<=n-2*k; i++){  // I need 2 subarrs of k len, thats why n-2*k
            if(isStrictlyInc(nums, i, k) and isStrictlyInc(nums, i+k, k)) return true;
        }
        return false;
    }
};