class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(l!=r){
                s[l]^=s[r];
                s[r]^=s[l];
                s[l]^=s[r];
            }
            l++;
            r--;
        }
    }
};