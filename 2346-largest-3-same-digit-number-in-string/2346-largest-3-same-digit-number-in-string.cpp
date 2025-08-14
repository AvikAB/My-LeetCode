class Solution {
public:
    string largestGoodInteger(string num) {
        string good = "";
        for(int i=0; i<num.size()-2; i++){
            if(num[i]==num[i+1] and num[i+1]==num[i+2]){
                good = max(good, num.substr(i,3));
            }
        }
        return good;
    }
};