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