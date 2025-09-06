class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        // prefix
        int left = 1;
        for(int i=0; i<n; i++){
            res[i] = left;       // put the val in the idx
            left *= nums[i];     // Update the val with curr idx val for next idx val
        }
        // suffix
        int right = 1;
        for(int i=n-1; i>=0; i--){
            res[i] *= right;       // put the val with the multiplication of prefix, because we use only one storage
            right *= nums[i];   // update the val
        }
        return res;
    }  
};










/* Compute prefix product (left prod) without including nums[i], suffix product (right prod)
without including nums[i] & multiply them. */