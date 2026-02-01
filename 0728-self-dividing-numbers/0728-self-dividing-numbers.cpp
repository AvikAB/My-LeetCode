class Solution {
public:
    bool check(int num){
        int temp = num;
        while(temp){
            int ld = temp%10;
            if(ld==0 or num%ld!=0) return false;
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i=left; i<=right; i++){
            if(check(i)) res.push_back(i);
        }
        return res;
    }
};