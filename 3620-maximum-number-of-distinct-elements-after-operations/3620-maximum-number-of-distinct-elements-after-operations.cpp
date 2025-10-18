class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int prev = -1e9;
        for(int i=0; i<nums.size(); i++){
            int currMn = max(nums[i]-k, prev+1);
            if(currMn <= nums[i]+k){
                prev = currMn;
                cnt++;
            }
        }
        return cnt;
    }
};