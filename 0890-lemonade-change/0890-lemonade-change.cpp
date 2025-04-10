class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        bool ok = true;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                if(five){
                    five--;
                    ten++;
                } else ok = false;
            } else {   // This is for 20
                if(five and ten){   // 15$ (10+5) return to customer
                    five--;
                    ten--;
                } else if(five>=3) five -= 3;   // 15$ (5+5+5) return to customer
                else ok = false;
            }
        }
        if(ok) return true;
        else return false;
    }
};