// BruteForce Approch:    O(n^2 * max_val)
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


// Optiomal approach using Prefix Sum & Suffix Sum:    O(n)

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int leftSum = 0, rightSum = 0;
        for(auto av:nums){
            rightSum += av;
        }
        for(int i=0; i<n; i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            if(nums[i]!=0) continue;  // must start from '0'
            if(leftSum==rightSum) cnt += 2;
            if(abs(leftSum-rightSum)==1) cnt++;
        }
        return cnt;
    }
};


/*
When starting at a zero, the sum of values on the left and sum of values on the right determine validity. If leftSum == rightSum, both directions work (+2). If they differ by 1, one direction works (+1)
*/
