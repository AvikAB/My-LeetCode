class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = max_element(arr.begin(),arr.end())-arr.begin();
        return n;
    }
};