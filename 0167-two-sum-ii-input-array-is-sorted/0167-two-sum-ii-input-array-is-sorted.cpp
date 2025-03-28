class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = 0;
        int l = 0, r = numbers.size()-1;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum==target){
                idx1 = l+1;
                idx2 = r+1;
                break;
            }
            if(sum>target) r--;
            else l++;
        }
        return {idx1, idx2};
    }
};