// O(n) using Bruteforce
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

// Using Maths (Arithmatic Progression) - O(1)

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


/*
Just use Arithmatic Progression:
 Total weeks = (n/7), remaining weeks = (n%7).
 Sum of Arithmatic Progression = terms/2 *(first ele + last ele)
 where, terms = n/7.

 How to find last ele?
 Tlast = first ele +(terms-1)*diff, here, diff = 7
 First tem of rem_weeks = 1+(num of passed weeks) = 1+(n/7)

Then, for loops from 1 to n%7 and add money then money++.
When n <= 7 then just for loops part will be works.

*/



//
