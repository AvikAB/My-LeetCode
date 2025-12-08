class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // cyclic sort: O(n)
        int n = nums.size();
        int i = 0;
        while(i<n){
            // check num in the range of [1,n],else given runtime error for any neg ele or 0
            if(nums[i]>0 and nums[i]<=n){
                int correctIdx = nums[i]-1;
                // check not in correct index then swap
                if(nums[i]!=nums[correctIdx]){
                    swap(nums[i], nums[correctIdx]);
                } else i++;
            } else i++;
        }

        // check first missing positive num
        for(int i=0; i<n; i++){
            if(nums[i] != i+1) return i+1;
        }
        // If all numbers 1..n are present then 1st missing num is n+1
        return n+1;
    }
};



// Another Approach:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        int i = 0;
        while(i<nums.size()){
            if(nums[i] > 0) {
                st.insert(nums[i]);
            }
            i++;
        }
        int comp = 1;
        for(auto it: st){
            if(it != comp) return comp;
            else comp++;
        }
        return comp;
    }
};
