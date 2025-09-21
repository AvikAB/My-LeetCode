class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int res = INT_MAX;
        for(auto &av:tasks){
            int end = av[0]+av[1];
            res = min(res, end);
        }
        return res;
    }
};