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
        for(int i=0; i<nums.size(); i++){
            if(dig(nums[i])==i) return i;
        }
        return -1;
    }
};