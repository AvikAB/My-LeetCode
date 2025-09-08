class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(char ch:s){
            int dis = (26-(ch-'a'))%26;   // (ch-'a') -> idx of that char, %26 for circular
            ans = max(ans, dis);
        }
        return ans;
    }
};