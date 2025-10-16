class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        int n = nums.size();
        map<int,int>m;
        for(int i=0; i<n; i++){
            int x = nums[i]%val;
            if(x<0) x=val+x;
            m[x]++;
        }
        int ans = 0;
        while(m[ans%val]--) ans++;
        return ans;
    }
};


/*  ans % val -> remainder of curr num (starts from 0) 
    m[ans % val] -> frequency of that remainder
    m[ans % val]-- -> 1 of frequency is used
    If there are too much remainder frequency of a num. Then we can use that freq
    (except 1 freq) because we need to maximum mex val. 
*/