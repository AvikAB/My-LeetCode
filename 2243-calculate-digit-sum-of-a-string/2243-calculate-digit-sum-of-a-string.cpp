class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string next;
            for(int i=0; i<s.size(); i+=k){  // i depends on k
                int sum = 0;
                for(char c: s.substr(i, k)){
                    sum += (c-'0');
                }
                next.append(to_string(sum));
            }
            s = next;
        }
        return s;
    }
};