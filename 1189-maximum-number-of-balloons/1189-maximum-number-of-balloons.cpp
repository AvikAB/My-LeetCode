class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq;
        for(auto av:text) freq[av]++;
        int b,a,l,o,n;
        b = freq['b'];
        a = freq['a'];
        l = freq['l'] / 2;  // available / required
        o = freq['o'] / 2;
        n = freq['n'];
        return min({b,a,l,o,n});
    }
};