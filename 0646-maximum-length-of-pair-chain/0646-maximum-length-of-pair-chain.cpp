class cmp{
    public:
    bool operator()(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
};


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp());
        int ans = 0;
        int freeAt = INT_MIN;
        for(int i=0; i<pairs.size(); i++){
            if(freeAt < pairs[i][0]){
                ans++;
                freeAt = pairs[i][1];
            }
        }
        return ans;
    }
};