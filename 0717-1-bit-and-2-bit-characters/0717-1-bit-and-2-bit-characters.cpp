class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int cnt1 = 0;
        for(int i=n-2; i>=0 and bits[i]==1; i--){
            cnt1++;
        }
        return (cnt1%2==0); 
        /* from the last pos if we get any 0 at this pos, then we will cnt how many 1 occured in
        their current left side, if its even times then 0 stays at last pos, if odd then it will
        make pair and create '10'
        */ 
    }
};