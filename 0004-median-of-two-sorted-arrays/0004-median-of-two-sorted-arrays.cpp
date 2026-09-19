class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(auto av:nums1) v.push_back(av);
        for(auto av:nums2) v.push_back(av);
        int n = v.size();
        sort(v.begin(), v.end());

        if(n%2) return v[n/2];
        else return (v[n/2 - 1] + v[n/2]) / 2.0;
    }
};