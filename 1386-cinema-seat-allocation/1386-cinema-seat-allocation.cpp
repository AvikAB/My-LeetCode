class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>>mp;  // row -> booked seats in row
        for(auto &reserve:reservedSeats){
            int row = reserve[0];
            int seat = reserve[1];
            mp[row].insert(seat);
        }
        int ans = (n-mp.size())*2;  // atmost we can take 2 groups at a time
        for(auto &[row, booked]:mp){
            auto isAvail = [&](int seat){
                return booked.find(seat)==booked.end();
            };

            bool grA = isAvail(2) and isAvail(3) and isAvail(4) and isAvail(5);
            bool grB = isAvail(4) and isAvail(5) and isAvail(6) and isAvail(7);
            bool grC = isAvail(6) and isAvail(7) and isAvail(8) and isAvail(9);

            if(grA and grC) ans += 2;  // atmost 2 groups are A & C
            else if(grA or grB or grC) ans++;
        }
        return ans;
    }
};