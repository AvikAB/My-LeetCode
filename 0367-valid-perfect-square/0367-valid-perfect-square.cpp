class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while(left<=right){
            int mid = left+(right-left)/2;
            long long int sq = 1LL*mid*mid;
            if(sq==num) return true;
            else if(sq>num) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};