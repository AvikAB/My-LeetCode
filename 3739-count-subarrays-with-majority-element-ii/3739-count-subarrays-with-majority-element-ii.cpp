#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T,null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target) nums[i] = 1;
            else nums[i] = -1;
        }

        ordered_set<int>os;
        os.insert(0);   // 0 for empty subarr
        long long ans = 0;
        int pref = 0;
        for(auto av:nums){
            pref += av;
            ans += os.order_of_key(pref);  // num of ele < pref_sum
            os.insert(pref);
        }
        return ans;
    }
};




/*
After convert the array into 1 or -1. Then the prefix sum will be p[r]-p[l-1] > 0 (subarray sum is > 0 means we have the targeted ele as majority).
From this, p[r] > p[l-1]. So we will get the ans by how many previous prefix sums (p[l-1]) is less than the curr pref sum (p[r]).
*/