class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>res;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]==key){
                int start = max(j-k, 0);
                int end = min(j+k, (int)nums.size()-1);
                if(!res.empty() and res.back()>=start){  // doing overlap
                    start = res.back()+1;
                }
                for(int i=start; i<=end; i++){
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};