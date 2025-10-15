class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string st1 = event1[0], et1 = event1[1];
        string st2 = event2[0], et2 = event2[1];
        return (st1 <= st2 and st2 <= et1) or (st2 <= st1 and st1 <= et2);
    }
};