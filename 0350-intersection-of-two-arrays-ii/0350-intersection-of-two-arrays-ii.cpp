class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(auto av:nums1){
            freq[av]++;
        }
        // for(int i=0; i<nums2.size(); i++){   // 1st implemention
        //     if(freq[nums2[i]]>0){
        //         ans.push_back(nums2[i]);
        //         freq[nums2[i]]--;  // decrease cnt to avoid extra duplicates
        //     }
        // }
        for(auto av:nums2){    // 2nd implemention
            if(freq[av]>0){
                ans.push_back(av);
                freq[av]--;
            }
        }
        // for(int i=0; i<nums2.size(); i++){   // 3rd implemention
        //     auto it = freq.find(nums2[i]);
        //     if(it!=freq.end() and it->second>0){
        //         ans.push_back(nums2[i]);
        //         it->second--;
        //     }
        // }
        return ans;
    }
};