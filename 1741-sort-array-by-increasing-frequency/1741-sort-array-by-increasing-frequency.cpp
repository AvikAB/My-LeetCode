class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int av: nums){
            freq[av]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(freq[a] == freq[b]) return a>b;   // if freq are equal then higher val first
            return freq[a] < freq[b];           // lower freq first
        });
        return nums;
    }
};