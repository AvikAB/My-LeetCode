class Solution {
public:
    unordered_map<unsigned long long, int> um;
    int solve(int i, unsigned long long uniqueChars, bool canChange, const string &s, int k) {
        unsigned long long key = ((unsigned long long)i << 27) | ((uniqueChars << 1) | (canChange));
        if(um.find(key) != um.end()) return um[key];
        if(i == s.size()) return 0;

        int charIdx = s[i] - 'a';
        unsigned long long newUniqChars = uniqueChars | (1ULL << charIdx);
        int uniqCharCnt = __builtin_popcountll(newUniqChars);
        int res;

        if(uniqCharCnt > k) res = 1 + solve(i + 1, (1ULL << charIdx), canChange, s, k);
        else res = solve(i + 1, newUniqChars, canChange, s, k);

        if(canChange){
            for(int newCharIdx = 0; newCharIdx < 26; ++newCharIdx) {
                unsigned long long changedSet = uniqueChars | (1ULL << newCharIdx);
                int changedCnt = __builtin_popcountll(changedSet);
                if(changedCnt > k) res = max(res, 1 + solve(i+1, (1ULL<<newCharIdx), false, s, k));
                else res = max(res, solve(i + 1, changedSet, false, s, k));
            }
        }
        return um[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        um.clear();
        return solve(0, 0ULL, true, s, k) + 1;
    }
};
