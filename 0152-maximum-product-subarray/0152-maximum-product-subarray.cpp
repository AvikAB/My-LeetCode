class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int prod = 1;
        for(int i=0; i<nums.size(); i++){
            prod *= nums[i];
            mx = max(mx, prod);
            if(prod==0) prod = 1;
        }
        prod = 1;
        for(int i=nums.size()-1; i>=0; i--){
            prod *= nums[i];
            mx = max(mx, prod);
            if(prod==0) prod = 1;
        }
        return mx;
    }
};










/* So we need to check from both sides, because single element can be a subarray. Also (prod<=0) given wrong, beacuse when we got neg value it starts a new subarray. But if we find another nums[i] which is neg then it will be the max product because both minus gives us plus. So, optimal is both side traversal */