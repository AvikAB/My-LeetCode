class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int low = 0;
        int high = x;
        int ans = 0;
        while(low<=high){
            long long int mid = low+(high-low)/2;
            long long int midsq = mid*mid;
            if(midsq>x){
                high = mid-1;
            } else {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};