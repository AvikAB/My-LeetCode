class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int, int>m;
        for(auto num:nums){
            m[num]++;
        }
        int sum = 0;
        for(int i=0; i<m.size(); i++){
            if(m[i]!=0 and m[i]%k==0){
                sum += (i * m[i]);
            }
        }
        return sum;
    }
};