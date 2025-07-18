class Solution {
public:
    #define ll long long int
    long long minimumDifference(vector<int>& nums) {
        ll N = nums.size();
        ll n = N/3;
        vector<ll> leftMinSum(N, 0);
        vector<ll> rightMaxSum(N,0);
        // answer lied on left side min sum - right side max sum, then it will give the min diff
        priority_queue<ll> maxHeap;  // leftMinSum -> remove greatest values for min
        ll leftSum = 0;
        for(int i=0; i<2*n; i++){
            maxHeap.push(nums[i]);
            leftSum += nums[i];
            if(maxHeap.size()>n){  // exceed the val of n then remove the max val of nums
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            leftMinSum[i] = leftSum;
        }

        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        ll rightSum = 0;
        for(int i=N-1; i>=n; i--){
            minHeap.push(nums[i]);
            rightSum += nums[i];
            if(minHeap.size()>n){
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            rightMaxSum[i] = rightSum;
        }

        ll ans = LLONG_MAX;
        for(int i=n-1; i<=2*n-1; i++){
            ans = min(ans, leftMinSum[i]-rightMaxSum[i+1]);
        }
        return ans;
    }
};