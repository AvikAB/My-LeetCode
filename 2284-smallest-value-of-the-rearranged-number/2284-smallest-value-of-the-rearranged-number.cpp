class Solution {
public:
    #define ll long long
    long long smallestNumber(long long num) {
        vector<ll>v;
        if(num==0) return 0;
        else if(num>0){    // if num is positive
            vector<ll>nonZero;
            while(num){
                ll ld = num%10;
                v.push_back(ld);
                if(ld!=0) nonZero.push_back(ld);
                num /= 10;
            }
            ll mn = *min_element(nonZero.begin(), nonZero.end());
            sort(v.begin(), v.end());
            ll res = mn;
            bool usedMn = false;
            for(auto av:v){    // the min and whole vector as a num
                if(av==mn and !usedMn){
                    usedMn = true;
                    continue;
                }
                res = res*10 + av;     
            }
            return res;
        } else {     // if num is negative
            num = abs(num);
            while(num){
                ll ld = num%10;
                v. push_back(ld);
                num /= 10;
            }
            sort(v.rbegin(), v.rend());
            ll res = 0;
            for(auto av:v){    // the whole v's ele are turned into a num
                res = res*10+av;
            }
            return res*(-1);
        }
    }
};