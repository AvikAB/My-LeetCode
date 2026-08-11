class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int st = start[0]+start[1];
        int end = target[0]+target[1];

        if((st%2==0 and end%2==0) or (st%2 and end%2)) return true;
        else return false;
    }
};