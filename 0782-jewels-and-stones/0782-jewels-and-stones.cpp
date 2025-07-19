class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // count each char of jewels in stones
        int cnt = 0;
        for(int i=0; i<jewels.size(); i++){
            cnt += count(stones.begin(), stones.end(), jewels[i]);
        }
        return cnt;
    }
};