class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>unique;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                unique.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int>s;
        for(int pairXor:unique){
            for(int i=0; i<nums.size(); i++){
                s.insert(pairXor^nums[i]);
            }
        }
        return s.size();
    }
};