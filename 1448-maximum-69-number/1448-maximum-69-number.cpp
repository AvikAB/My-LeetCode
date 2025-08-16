class Solution {
public:
    int maximum69Number (int num) {
        int placeVal = 0;
        int placeVal6 = -1;  // track where the six occurs
        int temp = num;
        while(temp){
            int ld = temp%10;
            if(ld==6) placeVal6 = placeVal;
            placeVal++;
            temp /= 10;
        }
        if(placeVal6 == -1) return num;   // never found a single six in num
        return num + 3*pow(10, placeVal6);
    }
};


/* 
    Intuition: just swap the first 6 to 9 of that num.
*/