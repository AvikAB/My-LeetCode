class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday$ = 1;
        while(n>0){
            int money = monday$;
            for(int days=1; days<=min(n,7); days++){
                ans += money;
                money++;
            }
            n -= 7;
            monday$++;
        }
        return ans;
    }
};