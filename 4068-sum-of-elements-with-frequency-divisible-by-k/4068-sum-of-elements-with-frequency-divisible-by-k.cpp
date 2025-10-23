class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int, int>m;
        for(auto num:nums){
            m[num]++;
        }
        int sum = 0;
        for(auto av:m){
            int val = av.first;
            int freq = av.second;
            if(freq%k==0) sum += val*freq;
        }
        return sum;
    }
};