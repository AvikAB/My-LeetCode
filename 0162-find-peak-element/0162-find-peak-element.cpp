class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = max_element(nums.begin(),nums.end())-nums.begin();
        return n;
    }
};