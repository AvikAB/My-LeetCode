class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto av:arr){
            m[av]++;
        }
        set<int>s;
        for(auto x:m){
            s.insert(x.second);
        }
        return m.size()==s.size();
    }
};