class Solution {
public:
    #define ll long long int
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        ll n = instructions.size();
        vector<bool>vis(n, false);
        ll tot = 0;
        ll i = 0;
        while(i>=0 and i<n and !vis[i]){
            vis[i] = true;
            if(instructions[i]=="add"){
                tot += values[i];
                i++;
            } else if(instructions[i]=="jump"){
                i += values[i];
            }
        }
        return tot;
    }
};