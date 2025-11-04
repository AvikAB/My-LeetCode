class Solution {
public:
    int findTopX(unordered_map<int, int>mp, int x){
        priority_queue<pair<int, int>>pq;   // max-heap to store {freq, num}
        for(auto av:mp){
            pq.push({av.second, av.first});
        }
        int sum = 0;
        while(x-- and !pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int freq = ele.first;
            int val = ele.second;
            sum += (freq*val);
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int>ans;
        int l = 0, r = 0;
        while(r<n){
            mp[nums[r]]++;
            if(r-l+1==k){
                ans.push_back(findTopX(mp, x));
                mp[nums[l]]--;     // remove left ele from map
                if(nums[l]==0){   // erase from map if freq is 0
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};