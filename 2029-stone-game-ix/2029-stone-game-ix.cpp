class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0,0,0};
        for(int i=0; i<stones.size(); i++){
            stones[i] %= 3;
            cnt[stones[i]]++;
        }

        if(cnt[0]%2==0) return cnt[1]!=0 and cnt[2]!=0;
        else return abs(cnt[2]-cnt[1])>=3;
    }
};


/*
cnt[0] is even then Alice wins when remainder 1 & 2 stones exist.
cnt[0] is odd then Alice needs a difference of at least 3 between the two non-zero groups.
*/