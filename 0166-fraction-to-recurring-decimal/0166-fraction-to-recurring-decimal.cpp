class Solution {
public:
    #define ll long long
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string res;
        if((numerator<0) ^ (denominator<0)) res.push_back('-');
        ll n = llabs((ll)numerator);
        ll d = llabs((ll)denominator);
        res += to_string(n / d);
        ll rem = n % d;
        if(rem==0) return res;
        res.push_back('.');
        unordered_map<ll, int> seen;
        while(rem!=0) {
            if(seen.find(rem) != seen.end()){
                int pos = seen[rem];
                res.insert(pos, "(");
                res.push_back(')');
                break;
            }
            seen[rem] = res.size();
            rem *= 10;
            int digit = rem / d;
            res.push_back(char('0' + digit));
            rem %= d;
        }
        return res;
    }
};