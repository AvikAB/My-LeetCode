#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    template <typename T> using ordered_set = tree<T,null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_set<long long>os;
        long long cnt = 0;
        for(int i=nums1.size()-1; i>=0; i--){
            long long val = nums1[i]-nums2[i];
            cnt += os.size() - os.order_of_key(val);
            os.insert(val+diff);
        }
        return cnt;
    }
};