class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;  // weeks
        int firstEle = 28;  // sum of first week as per condition
        int lastEle = 28+(terms-1)*7;   // formula of finding nth ele of AP, d=7, firstEle=28
        int ans = terms*(firstEle+lastEle)/2;   // Sum of Arithmatic Progression (AP)

        // remaing days is (n%7), processing starts from below
        // its also work when n is <7
        int startMoney = 1+terms;
        for(int day=1; day<=(n%7); day++){
            ans += startMoney;
            startMoney++;
        }
        return ans;
    }
};