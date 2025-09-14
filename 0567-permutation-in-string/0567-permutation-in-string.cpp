//Approach-1 (Brute Force) - TLE
//T.C : O(n! * m)
//S.C : O(n)
class Solution {
public:
    int n;
    bool result;
    void solve(int idx, string& s1, string& s2) {
        if (idx == n) {
            if (s2.find(s1) != string::npos) {
                result = true;
            }
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(s1[i], s1[idx]);
            solve(idx + 1, s1, s2);
            swap(s1[i], s1[idx]);
            // Early exit if a permutation has been found in s2
            if (result == true) return;
        }
    }

    bool checkInclusion(string s1, string s2) {
        n = s1.length();
        result = false;  // Reset result for each call
        solve(0, s1, s2);
        return result;  // Return whether a permutation of s1 is found in s2
    }
};


// Approach: 2 (Sorting - O(n log n)):
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        sort(s1.begin(), s1.end());
        for(int i=0; i<=s2.size()-s1.size(); i++){
            string substring = s2.substr(i, s1.size());  // same substr of s1's size
            sort(substring.begin(), substring.end());
            if(s1==substring) return true;
        }
        return false;
    }
};
