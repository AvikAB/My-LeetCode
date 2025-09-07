class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool ok = true;
        int num = nums[0];
        for(int i=0; i<n; i++){
            if(num!=nums[i]){
                ok = false;
                break;
            }
        }
        if(ok) return 0;  // all eles are same
        else return 1;
    }
};