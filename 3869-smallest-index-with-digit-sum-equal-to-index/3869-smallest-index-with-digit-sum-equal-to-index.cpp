class Solution {
public:
    int dig(int n){
        int sum = 0;
        while(n){
            int ld = n%10;
            sum += ld;
            n /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int idx = -1;
        for(int i=0; i<nums.size(); i++){
            if(dig(nums[i])==i){
                if(idx==-1) idx = i;  // idx not updated yet
                else idx = min(idx, i);  // updated idx, now find the min of it
            }
        }
        return idx;
    }
};