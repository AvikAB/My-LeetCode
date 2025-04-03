class Solution {
    #define ll long long int
    vector<bool>isPrime;
    vector<ll>primes;

    void PrimeGen(ll n){
        isPrime.assign(n + 1, false);
        for(int i=3; i<=n; i+=2) isPrime[i] = 1;

        ll sqr = sqrt(n);
        for(int i=3; i<=sqr; i+=2){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i){
                    isPrime[j] = 0;
                }
            }
        }

        isPrime[2] = 1;
        primes.push_back(2);

        for(int i=3; i<=n; i+=2){
            if(isPrime[i]==1) primes.push_back(i);
        }
    }
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        PrimeGen(n-1);
        return primes.size();
    }
};