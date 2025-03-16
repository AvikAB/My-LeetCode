#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset os;
        vector<int>ans(nums.size());
        for(int i=nums.size()-1; i>=0; i--){
            os.insert(nums[i]);
            ans[i] = os.order_of_key(nums[i]);
        }
        return ans;
    }
};