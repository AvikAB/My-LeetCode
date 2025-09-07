class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>s(friends.begin(), friends.end());
        vector<int>ans;
        for(auto av:order){
            if(s.count(av)) ans.push_back(av);
        }
        return ans;
    }
};