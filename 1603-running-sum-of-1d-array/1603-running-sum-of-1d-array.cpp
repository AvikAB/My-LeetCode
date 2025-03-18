class Solution {
public:
    vector<int> runningSum(vector<int>&a) {
        int n=a.size();
        vector<int>preSum(n);
        preSum[0]=a[0];
        for(int i=1; i<n; i++){
            preSum[i]=preSum[i-1]+a[i];
        }
        return preSum;
    }
};