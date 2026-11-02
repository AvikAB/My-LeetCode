class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        long long int sum = accumulate(nums.begin(), nums.end(), 0ll);
        int mn = *min_element(nums.begin(), nums.end());
        ans = sum-mn*nums.size();
        return ans;
    }
};



/*
Just think about reverse way.
Ultimately, to decrease the gap betwn min & mx. When the gap=0 then all eles are equal.

increment by 1: Then I should focus all (n-1) eles.
decrement by 1: then I just need to focus only the mx ele. 

So, I can use a loop upto n, where it will find the gap between min & curr_ele,
because we will just change the mx, after decrementing it will come to the min ele, take it as moves and print it.

So, (nums[0]-mn) + (nums[1]-mn) + ... + (nums[n-1]-mn)
  => (nums[0]+nums[1]+...+nums[n-1]) - mn
  => sum - mn *n
  There is total n times to check, so multiply n.
*/ 