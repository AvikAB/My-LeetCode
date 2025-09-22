class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currStreak = 0, mxStreak = 0;
        for(auto av:nums){
            currStreak += av;
            mxStreak = max(mxStreak, currStreak);
            if(av==0) currStreak = 0;
        }
        return mxStreak;
    }
};


// Just Kadane's Algo, The problem says that nums will be 0 or 1. If av is 1 increase the currStreak and update the mxStreak. If av is 0 then start the new currStreak.