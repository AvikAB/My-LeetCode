class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>res;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]==key){
                int start = max(j-k, 0);
                int end = min(j+k, (int)nums.size()-1);
                for(int i=start; i<=end; i++){
                    res.insert(i);
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};