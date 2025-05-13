class Solution {
public:
    int minDeletion(string s, int k) {
        map<char, int> m;
        for(auto av:s){
            m[av]++;
        }
        vector<int>v;
        for(auto av:m){
            v.push_back(av.second);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int sz = v.size()-k;
        for(int i=0; i<sz; i++){
            ans += v[i];
        }
        return ans;
    }
};