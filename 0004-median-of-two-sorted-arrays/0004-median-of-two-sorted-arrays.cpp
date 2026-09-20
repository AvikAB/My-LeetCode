class Solution {
public:
    // two pointer:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int tot = (n+m);
        int mid1 = (tot-1)/2;   // indexOfmid1
        int mid2 = tot/2;       // indexOfmid2
        int i=0, j=0;
        int cnt = 0;
        int a=0, b=0;
        while(cnt<=mid2){
            int val;
            if(i<n and (j>=m or nums1[i]<=nums2[j])) val = nums1[i++];
            else val = nums2[j++];
            if(cnt==mid1) a = val;
            if(cnt==mid2) b = val;
            cnt++;
        }
        return (tot%2==0) ? (a+b)/2.0 : b;
    }
};


// O(n+m/2) ~ O(n+m)