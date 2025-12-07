class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 or k==0) return;
        k %= n;  // it ensures k within bounds (0 to n-1) when k>n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), (nums.begin()+k));
        reverse(nums.begin()+k, nums.end());
    }
};

/*
Steps: Reverse entire araay. Reverse first k eles. Reverse last n-k eles.
*/