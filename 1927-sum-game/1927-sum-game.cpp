class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0, cnt = 0;
        for(int i=0; i<n; i++){
            bool firstHalf = i<(n/2);
            if(num[i]=='?'){
                cnt += firstHalf ? 1 : -1;
            } else {
                int dig = num[i] - '0';
                diff += firstHalf ? dig : -dig;
            }
        }
        return 2*diff != -9*cnt;
    }
};