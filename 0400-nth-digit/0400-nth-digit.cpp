class Solution {
public:
    #define ll long long
    int findNthDigit(int n) {
        ll k = n;
        ll len = 1;  // curr dig length
        ll cnt = 9;  // how many nums in that len
        ll st = 1;   // first num in that len
        while(k>len*cnt){
            k -= (len*cnt);
            len++;
            cnt *= 10;
            st *= 10;
        }

        st += (k-1)/len;  // find actual num

        // find the dig within the num
        string ans = to_string(st);
        int res = ans[(k-1)%len] - '0';
        return res;
    }
};