class Solution {
public:
    string largestEven(string s) {
        while(!s.empty()){
            int ld = s.back()-'0';
            if(ld%2==0) return s;
            s.pop_back();
        }
        return "";
    }
};