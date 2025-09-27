class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, hi = arr.size();
        while(low<hi){
            int mid = low+(hi-low)/2;
            int miss = arr[mid] - (mid+1);
            if(miss < k) low = mid+1;   // move right
            else hi = mid;              // move left
        }
        return low+k;
    }
};


// How many nums are missing up to idx i: arr[i]-(i+1)