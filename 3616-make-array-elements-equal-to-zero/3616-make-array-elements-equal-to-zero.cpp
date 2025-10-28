class Solution {
public:
    bool isValid(vector<int>nums, int dir, int curr){
        int n = nums.size();
        while(curr>=0 and curr<n){
            if(nums[curr]==0) curr += dir;  // when ele is 0 then its works for only one direction, move in curr direction
            else {  // when ele !=0 then decrease the val by 1 & reverse the direction
                nums[curr]--;
                if(dir==-1) dir = 1;
                else dir = -1;
                curr += dir;   // move in the new dir
            }
        }
        bool ok = true;
        for(auto av:nums){
            if(av!=0){
                ok = false;
                break;
            }
        }
        return ok;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0) continue;    // skip, must start at '0'
            else {    // if ele is 0, try both directions
                cnt += isValid(nums, -1, i);   // start at i, moving left
                cnt += isValid(nums, 1, i);    // start at i, moving right
            }
        }
        return cnt;
    }
};