class Solution {
public:
    int cntR(string &t){
        int sc = 0;
        for(int i=0; i<t.size()-1; i++){
            if(t[i]==t[i+1]) sc++;
        }
        return sc;
    }
    int countRotations(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            string rot = s.substr(i)+s.substr(0,i);
            if(cntR(rot)==k) cnt++;
        }
        return cnt;
    }
};