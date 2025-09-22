// Using Hashmap:
// Time Comp: O(n+u), where u is the num of unique element, Overall TC: O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int mxfr = 0;
        for(auto &p:freq){
            mxfr = max(mxfr, p.second);
        }
        int ans = 0;
        for(auto &p:freq){
            if(p.second == mxfr) ans += p.second;
        }
        return ans;
    }
};


// Without hashmap:
// Time Comp: O(n+101) ~ O(n)
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
