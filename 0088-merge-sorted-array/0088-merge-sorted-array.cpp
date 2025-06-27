class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;    // last ele of nums1
        int j = n-1;    // last ele of nums2
        int k = m+n-1;  // last position of merged array in nums1
        while(i>=0 and j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while(j>=0){     // If ele left in nums2 (nums1 is completed)
            nums1[k--] = nums2[j--];
        }
    }
};