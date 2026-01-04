class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n:nums){
            // find divisors
            vector<int>div;
            for(int d=1; d*d<=n; d++){
                if(n%d==0){
                    div.push_back(d);  // add first divisor
                    if(d != n/d) div.push_back(n/d);  // d & n/d are different divisors
                }
            }
            // only process if exactly 4 divisors
            if(div.size()==4){
                int sum = 0;
                for(auto av:div){
                    sum += av;
                }
                ans += sum;
            }
        }
        return ans;
    }
};