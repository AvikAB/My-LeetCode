class Solution {
public:
    int maxProduct(int n) {
        vector<int>dig;
        while(n){
            dig.push_back(n%10);
            n /= 10;
        }
        sort(dig.begin(), dig.end());
        return dig[dig.size()-1] * dig[dig.size()-2];
    }
};