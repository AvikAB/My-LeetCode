class Solution {
public:
    #define ll long long 
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<tuple<ll,ll,ll>>st;
        for(int i=n-1; i>=0; i--){
            ll pos = position[i];
            ll spd = speed[i];
            ll l = pos;
            ll r = pos;
            while(!st.empty()){
                auto [Gleft, Gright, Gspd] = st.back();
                // ll r_pos = st.back().first;
                // ll r_spd = st.back().second;
                if(spd>Gspd or Gleft-pos<=distance){
                    r = Gright;
                    spd = Gspd;
                    st.pop_back();
                } else break;
            }
            st.push_back({l,r,spd});
        }
        return st.size();
    }
};