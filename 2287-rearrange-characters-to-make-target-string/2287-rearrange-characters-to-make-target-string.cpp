class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.size();
        vector<int>availableCnt(26,0);
        for(auto av:s){
            availableCnt[av-'a']++;
        }
        vector<int>requiredCnt(26, 0);
        for(auto av:target){
            requiredCnt[av-'a']++;
        }
        int ans = INT_MAX;
        for(auto av:target){
            ans = min(ans, availableCnt[av-'a']/requiredCnt[av-'a']);
        }
        return ans;
    }
};