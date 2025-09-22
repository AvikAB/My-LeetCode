class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int mxfr = *max_element(freq.begin(), freq.end());
        int ans = 0;
        for(auto av:freq){
            if(av == mxfr) ans += av;
        }
        return ans;
    }
};