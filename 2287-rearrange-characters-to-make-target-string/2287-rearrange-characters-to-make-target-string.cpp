class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.size();
        unordered_map<char,int> available, required;
        for(auto av:s) available[av]++;
        for(auto av:target) required[av]++;

        int ans = INT_MAX;
        for(auto &[ch, cnt]:required){
            ans = min(ans, available[ch] / cnt);  // formula: (availCnt/reqCnt)
        }
        return ans;
    }
};