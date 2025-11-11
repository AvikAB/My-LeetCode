class Solution {
public:
    int memo[101][101][601];   // m,n,i are changeable thats why 3D array

    int solve(vector<pair<int, int>>&count, int m, int n, int i){
        if(i>=count.size() or (m==0 and n==0)) return 0;   // base case

        if(memo[m][n][i]!=-1) return memo[m][n][i];

        int take = 0;
        if(count[i].first<=m and count[i].second<=n){
            take = 1 + solve(count, m-count[i].first, n-count[i].second, i+1);  // we got an ele, thats why 1 + solve( for next ele )
        }
        int skip = solve(count, m, n, i+1);   // doesn't take anything
        return memo[m][n][i] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count(strs.size());
        for(int i=0; i<strs.size(); i++){
            int cntZero = 0;
            int cntOne = 0;
            for(char &av:strs[i]){
                if(av=='0') cntZero++;
                else cntOne++;
            }
            count[i] = {cntZero, cntOne};
        }
        memset(memo, -1, sizeof(memo));
        return solve(count, m, n, 0);
    }
};