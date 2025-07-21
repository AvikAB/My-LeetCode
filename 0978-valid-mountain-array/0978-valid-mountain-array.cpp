class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        // mountain means it always up, peak and down
        int i = 0;
        while(i+1<n and arr[i]<arr[i+1]) i++;   // go up
        if(i==0 or i==n-1) return false;   // peak can't be the first or last
        while(i+1<n and arr[i]>arr[i+1]) i++;   // go down
        return i==n-1;   // return true if it reaches the last ele of array
    }
};