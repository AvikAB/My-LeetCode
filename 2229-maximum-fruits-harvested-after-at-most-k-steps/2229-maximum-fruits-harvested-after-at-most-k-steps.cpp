class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefSum(n);
        vector<int> positions(n);
        for(int i=0; i<n; i++){
            positions[i] = fruits[i][0];
            prefSum[i] = fruits[i][1] + (i>0 ? prefSum[i-1] : 0);
        }
        int mx = 0;
        for(int d=0; d<=(k/2); d++){
            // case 1: moved d steps to the left
            int rem = k-2*d;
            int i = startPos - d;
            int j = startPos + rem;
            int left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            int right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;
            if(left<=right){
                int total = prefSum[right] - (left>0 ? prefSum[left-1] : 0);
                mx = max(mx, total);
            }

            // case 2: moved d to the right hand side
            i = startPos - rem;
            j = startPos + d;
            left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;
            if(left<=right){
                int total = prefSum[right] - (left>0 ? prefSum[left-1] : 0);
                mx = max(mx, total);
            }
        }
        return mx;
    }
};