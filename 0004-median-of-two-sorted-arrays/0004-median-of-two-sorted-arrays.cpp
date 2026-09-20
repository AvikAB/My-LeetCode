class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);  // always doing bin search in small array
        }

        int l = 0, r = m;
        while(l<=r){
            int mid = (l+r)/2;  // ele taken from nums1 into left_half
            int rem_left = (m+n+1)/2-mid;  // ele taken from nums2 into left_half

            // left_half
            int l1 = (mid==0) ? INT_MIN : nums1[mid-1];
            int l2 = (rem_left==0) ? INT_MIN : nums2[rem_left-1];

            // right_half
            int r1 = (mid==m) ? INT_MAX : nums1[mid];
            int r2 = (rem_left==n) ? INT_MAX : nums2[rem_left];

            if(l1<=r2 and l2<=r1){
                if((m+n)%2) return max(l1, l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }

            if(l1>r2){  // not sorted
                r = mid-1;
            } else l = mid+1;
        }
        return -1;
    }
};


// O(log(m+n))

/*
There will be total 2 partition: left_half, right_half
- left_half's all vals always will be lesser than the right_half.
[....l1 r1.....]
[....l2 r2.....]
- Condition: l1<=r2 and l2<=r1.
We know l1<=r1 because of its sorted, we also need to check that 1st left_half is less than the 2nd right_half for valid partition to get median.

- mid: how many eles we can take from nums1 into left_half.
- rem_left: the remaining size of left_half from the nums2.

- For odd size, left_half's largest val will be median.
- For even size, left_half's max & right_half's min's avg will be median.
*/