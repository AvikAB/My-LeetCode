class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int mxv = *max_element(nums.begin(),  nums.end());
        int B = 0;
        while((1<<B)<=mxv) B++;
        int go = (1<<B)-1;
        vector<int>v(1<<B, 0);
        for(int num:nums){
            v[num] = max(v[num], num);
        }
        for(int i=0; i<B; i++){
            for(int mask=0; mask<=go; mask++){
                if(mask & (1<<i)){
                    int u = mask^(1<<i);
                    v[mask] = max(v[mask], v[u]);
                }
            }
        }
        long long ans = 0;
        for(int num:nums){
            int comp = go ^ num;
            int y = v[comp];
            if(y != 0) ans = max(ans, 1LL*num*y);
        }
        return ans;
    }
};