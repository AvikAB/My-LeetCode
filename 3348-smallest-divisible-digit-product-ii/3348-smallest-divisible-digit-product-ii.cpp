class Solution {
public:
    #define ll long long

    string func(ll num, ll len){
        string s;
        for(int dig=9; dig>=2; dig--){
            while(num % dig==0){
                s.push_back(dig + '0');
                num /= dig;
            }
        }
        
        while(s.size()<len){
            s.push_back('1');
        }
        
        reverse(s.begin(), s.end());
        return s;
    }

    string smallestNumber(string num, long long t) {
        ll n = num.size();
        
        // Check if t has any prime factor > 7
        ll temp = t;
        for(ll primeFact : {2, 3, 5, 7}){
            while(temp % primeFact==0){
                temp /= primeFact;
            }
        }
        if(temp!=1) return "-1";

        // Precompute remaining factor needed after each position
        vector<ll> remFact(n+1, t);
        for(int i=0; i<n; i++){
            ll curr = num[i]-'0';
            if(curr==0){
                break;
            }
            remFact[i+1] = remFact[i] / gcd(remFact[i], (ll)curr);
        }

        // If already satisfies, return original
        if(remFact[n]==1){
            return num;
        }

        ll zero = num.find('0');
        ll zeroIdx = n-1;
        if(zero!=-1) zeroIdx = zero;

        // Try to increment from right to left
        for(int i=zeroIdx; i>=0; i--){
            ll req = remFact[i];
            ll free = n-1-i;
            
            // Try digits greater than current
            for(int dig=(num[i]-'0')+1; dig<=9; dig++){
                ll new_req = req / gcd(req, dig);
                string reqNum = func(new_req, free);
                if(reqNum.size()==free){
                    return num.substr(0, i) + char(dig+'0') + reqNum;
                }
            }
        }

        string res = func(t, n+1);
        if(!res.empty()) return res;
        return "-1";
    }
};