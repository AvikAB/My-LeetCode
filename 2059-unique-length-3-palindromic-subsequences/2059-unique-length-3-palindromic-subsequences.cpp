class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // char's first & last occurrence
        map<char, int> first, last;
        // Record first & last occurrence
        for(int i=0; i<s.size(); i++){
            last[s[i]] = i;
            if(first.find(s[i]) == first.end()){
                first[s[i]] = i;
            }
        }

        int cnt = 0;
        for(auto [ch, l]:first){   // picks first's char and their first occurence position
            int r = last[ch];   // same char's last occurence
            set<char> middleChars;
            // count unique middle characters 'x' between l & r
            for(int i=l+1; i<r; i++){
                middleChars.insert(s[i]);
            }
            cnt += middleChars.size();
        }
        return cnt;
    }
};