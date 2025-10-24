class Solution {
public:
    bool isBalanced(int num){
        vector<int>freq(10);
        while(num){
            int dig = num%10;
            freq[dig]++;
            num /= 10;
        }
        for(int d=0; d<10; d++){
            if(freq[d]!=0 and freq[d]!=d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1224444; i++){
            if(isBalanced(i)) return i;
        }
        return -1;
    }
};