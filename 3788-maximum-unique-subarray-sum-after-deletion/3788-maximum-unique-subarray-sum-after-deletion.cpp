class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        unordered_set<int>us(nums.begin(), nums.end());
        for(auto av:us){
            if(av>0) sum += av;
        }
        if(sum==0) return *max_element(nums.begin(), nums.end());
        return sum;
    }
};