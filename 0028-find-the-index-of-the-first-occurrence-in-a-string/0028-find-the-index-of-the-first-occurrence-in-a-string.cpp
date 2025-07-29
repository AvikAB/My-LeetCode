class Solution {
public:
    int strStr(string haystack, string needle) {
        int nIdx = 0;
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i]==needle[nIdx]) nIdx++;  // if char are same then check it for needle, so that increment nIdx aka needle index
            else {
            i = i-nIdx;  // start from the next index of haystack
            nIdx = 0;  // needle should start from index 0, if there is mismatch
        }

        if(nIdx==needle.size()) return i-needle.size()+1;  // return the first index
        }
        return -1;
    }
};