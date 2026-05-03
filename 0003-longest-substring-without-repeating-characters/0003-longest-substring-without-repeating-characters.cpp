class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int mxLen = 0;
        unordered_map<char,int>m;  // {char, idx}
        for(int right=0; right<s.size(); right++){
            char c = s[right];
            if(m.count(c) and m[c]>=left){
                left = m[c]+1;
            }
            m[c] = right;
            mxLen = max(mxLen, right-left+1);
        }
        return mxLen;
    }
};