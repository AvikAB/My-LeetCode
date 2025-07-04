class Solution {
public:
    #define ll long long int
    char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0;
        vector<ll> length;
        ll len = 1;

        for(auto av:operations){  // find the length untill reach k, every time len will be power of 2
            len *= 2;
            length.push_back(len);
            if(len>=k) break;
        }
        // Backtracking:
        for(int i=length.size()-1; i>=0; i--){
            ll half = length[i]/2;
            ll op = operations[i];
            if(k>half){   // character is in 2nd half
                k -= half;
                if(op==1) shift++;
            }
        }
        return (char)((('a'-'a'+shift)%26)+'a');
    }
};