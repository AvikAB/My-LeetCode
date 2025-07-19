class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // first 2 nums will be a and b, then apply two pointers on b+1 to n-1 for finding the value of c and d
        for(int a=0; a<n; a++){
            if(a>0 and nums[a]==nums[a-1]) continue; // skip duplicate for a
            for(int b=a+1; b<n; b++){
                if(b>a+1 and nums[b]==nums[b-1]) continue;  //skip duplicate for b
                int c = b+1, d = n-1;   // two pointers
                while(c<d){
                    long long sum = (long long)nums[a]+nums[b]+nums[c]+nums[d];
                    if(sum<target) c++;
                    else if(sum>target) d--;
                    else {  // sum==target
                        while(c<d and nums[c]==nums[c+1]) c++;
                        while(c<d and nums[d]==nums[d-1]) d--;
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++, d--;
                    }
                }
            }
        }
        return ans;
    }
};