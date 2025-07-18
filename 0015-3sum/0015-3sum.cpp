class Solution {
public:
    vector<vector<int>>ans;
    void twoSum(vector<int>&nums, int target, int i, int j){
        while(i<j){
            if(nums[i]+nums[j]>target) j--;
            else if(nums[i]+nums[j]<target) i++;
            else {   // first we will remove the duplicates from nums
                while(i<j and nums[i]==nums[i+1]) i++;
                while(i<j and nums[j]==nums[j-1]) j--;
                ans.push_back({-target, nums[i], nums[j]});
                i++, j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return {};
        ans.clear();
        sort(nums.begin(), nums.end());
        // fixing one element: n1
        for(int i=0; i<n; i++){
            if(i>0 and  nums[i]==nums[i-1]) continue;
            int n1 = nums[i];
            int target = -n1;
            twoSum(nums, target, i+1, n-1);  // it will find n2 and n3. i+1 and n-1 is the remaining part of nums after selecting n1 or target
        }
        return ans;
    }
};