class Solution {
public:
    // Memoization approach:
    int n;
    bool isPalin(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;

            i++, j--;
        }
        return true;
    }

    int solve(string &s, int k, int i, int j, vector<vector<int>> &memo){
        if(i>=n or j>=n) return 0;  // base case

        if(memo[i][j]!=-1) return memo[i][j];

        if(isPalin(s, i, j)){
            int take = 1+solve(s,k, j+1, j+k, memo);
            int spread = solve(s,k, i, j+1, memo);
            int slide = solve(s,k, i+1, j+1, memo);
            return memo[i][j] = max({take, spread, slide});
        } else {
            int spread = solve(s,k, i, j+1, memo);
            int slide = solve(s,k, i+1, j+1, memo);
            return memo[i][j] = max(spread, slide);
        }
    }

    int maxPalindromes(string s, int k) {
        n = s.size();
        if(k==1) return n;
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));  // i,j 2 states are changing thats why 2d 
        return solve(s, k, 0, k-1, memo);  // starting from 0 and at least k sized palindrome
    }
};


/*
If substr is Palindrome then there is total 3 choices:
    1. Take it cnt=1 and check remaining substr. (idxs for nonoverlap)
    2. If curr substr is not palindrome then spread the size & check.
    3. Slide if curr k-sized are not a palindrome, start+1, end+1 for non-overlap.
    Take max of these and that is ans.

If substr is not Plaindrome then there is total 2 choices:
    1. If curr substr is not palindrome then spread the size & check.
    2. Slide if curr k-sized are not a palindrome, start+1, end+1 for non-overlap.
    Take max of these & that is ans.
*/