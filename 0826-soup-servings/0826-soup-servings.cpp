class Solution {
public:
    vector<pair<int, int>> serves = {{100,0}, {75,25}, {50,50}, {25,75}};
    vector<vector<double>>memo;
    double solve(int a, int b){
        if(a<=0 and b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0.0;
        if(memo[a][b] != -1.0) return memo[a][b];
        double prob = 0.0;
        for(auto &av:serves){
            int a_taken = av.first;
            int b_taken = av.second;
            prob += solve(a-a_taken, b-b_taken);
        }
        return memo[a][b] = 0.25 * prob;
    }

    double soupServings(int n) {
        // here, a is easy to finish first as compare to b, because we can use a 100ml
        if(n>=5000) return 1;   // if n is increases then the finshing probability of a is closed to 1
        memo.resize(n+1, vector<double>(n+1, -1.0));
        return solve(n, n);
    }
};