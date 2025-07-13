class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0;
        int cnt = 0;
        while(i<players.size() and j<trainers.size()){
            if(players[i]<=trainers[j]){
                i++, j++;
                cnt++;
            } else j++;
        }
        return cnt;
    }
};