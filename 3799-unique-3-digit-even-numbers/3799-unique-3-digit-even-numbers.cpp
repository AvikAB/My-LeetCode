class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>us;
        int n = digits.size();
        for(int i=0; i<n; i++){
            if(digits[i]==0) continue;
            for(int j=0; j<n; j++){
                if(j==i) continue;
                for(int k=0; k<n; k++){
                    if(k==i or k==j) continue;
                    if(digits[k]%2==0){
                        int num = digits[i]*100+digits[j]*10+digits[k];
                        us.insert(num);
                    }
                }
            }
        }
        return us.size();
    }
};