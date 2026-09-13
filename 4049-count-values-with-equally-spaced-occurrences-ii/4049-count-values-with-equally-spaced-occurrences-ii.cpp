class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>indices;
        for(int i=0; i<n; i++){
            indices[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto &[val,idx]:indices){
            if(idx.size()<3) continue;
            int gap = idx[1]-idx[0];
            bool special = true;
            for(int i=2; i<idx.size(); i++){
                if(idx[i]-idx[i-1]!=gap){
                    special = false;
                    break;
                }
            }
            if(special) cnt++;
        }
        return cnt;
    }
};