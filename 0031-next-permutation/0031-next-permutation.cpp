class Solution {
public:
    #define ll long long
    void nextPermutation(vector<int>& nums) {
        ll n = nums.size();
        ll choosen_idx = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                choosen_idx = i-1;
                break;
            }
        }
        if(choosen_idx!=-1){
            ll swap_idx = choosen_idx;
            for(int i=n-1; i>=choosen_idx+1; i--){
                if(nums[i]>nums[choosen_idx]){
                    swap_idx = i;
                    break;
                }
            }
            swap(nums[choosen_idx], nums[swap_idx]);
        }
        reverse(nums.begin()+choosen_idx+1, nums.end());
    }
};
