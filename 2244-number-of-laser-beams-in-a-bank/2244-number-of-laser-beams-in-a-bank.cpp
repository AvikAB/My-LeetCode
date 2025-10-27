class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prevDevCnt = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            int currDevCnt = 0;
            for(char av:bank[i]){
                if(av=='1') currDevCnt++;
            }
            if(currDevCnt>0){
                ans += (currDevCnt * prevDevCnt);
                prevDevCnt = currDevCnt;   // update prev when curr!=0,if curr==0 then prev=prev
            }
        }
        return ans;
    }
};