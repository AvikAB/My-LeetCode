class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, curr, res;
        for(int i=0; i<arr.size(); i++){
            for(const int &av:prev){
                curr.insert(av|arr[i]);
                res.insert(av|arr[i]);
            }
            // that single ele is also the part of subarrays & their or will same
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return res.size();
    }
};