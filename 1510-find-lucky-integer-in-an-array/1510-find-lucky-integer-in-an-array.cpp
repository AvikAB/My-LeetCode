class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        int cnt = -1;
        for(auto av:arr){
            mp[av]++;
        }
        for(auto av: mp){
            if(av.first == av.second) cnt = max(cnt, av.first);
        }
        return cnt;
    }
};