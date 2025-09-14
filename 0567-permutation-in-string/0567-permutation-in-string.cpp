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
​
        for (int i = idx; i < n; i++) {
            swap(s1[i], s1[idx]);
            solve(idx + 1, s1, s2);
            swap(s1[i], s1[idx]);
            // Early exit if a permutation has been found in s2
            if (result == true) 
                return;
        }
    }
​
    bool checkInclusion(string s1, string s2) {
        n = s1.length();
        result = false;  // Reset result for each call
        solve(0, s1, s2);
        return result;  // Return whether a permutation of s1 is found in s2
    }
};


// Approach - 2: (Sorting)
// TC: O((m-n) * nlogn)
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

// Approach - 3: (Sliding Window - O(n+m))
// n -> s1.size(), m -> s2.size()

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> s1_freq, s2_freq;
        for(char c:s1){
            s1_freq[c]++;
        }
        int i=0;
        for(int j=0; j<s2.size(); j++){
            s2_freq[s2[j]]++;
            // if window's size exceeds s1.size(), then remove the leftmost char
            if(j-i+1 > s1.size()){
                s2_freq[s2[i]]--;   // decrease the leftmost char's freq count
                if(s2_freq[s2[i]]==0){  // if that leftmost's cnt is overall 0 then remove from the map 
                    s2_freq.erase(s2[i]);
                }
                i++;
            }
            if(s1_freq == s2_freq) return true;
        }
        return false;
    }
};
