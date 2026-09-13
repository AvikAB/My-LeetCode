class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>indices;
        for(int i=0; i<nums.size(); i++){
            indices[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto &[val, idx]:indices){
            if(idx.size()==3){
                if(idx[1]-idx[0]==idx[2]-idx[1]) cnt++;
            }
        }
        return cnt;
    }
};