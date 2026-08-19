class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int>mp;  // row -> booked seats in row
        for(auto &reserve:reservedSeats){
            int row = reserve[0];
            int seat = reserve[1];
            mp[row] |= (1<<seat);
        }
        int ans = (n-mp.size())*2;  // atmost we can take 2 groups at a time
        for(auto &[row, booked]:mp){
            int maskA = (1<<2) | (1<<3) | (1<<4) | (1<<5);
            int maskB = (1<<4) | (1<<5) | (1<<6) | (1<<7);
            int maskC = (1<<6) | (1<<7) | (1<<8) | (1<<9);

            bool grA = (booked & maskA) == 0;  // all seats are available
            bool grB = (booked & maskB) == 0;
            bool grC = (booked & maskC) == 0;

            if(grA and grC) ans += 2;  // atmost 2 groups are A & C
            else if(grA or grB or grC) ans++;
        }
        return ans;
    }
};