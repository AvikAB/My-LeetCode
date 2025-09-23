class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto av:s){
            freq[av]++;
        }
        vector<pair<int, char>>v;
        for(auto &av:freq){
            v.push_back({av.second, av.first});   // {occurrence, char}
        }
        sort(v.begin(), v.end(),[](auto &a, auto &b){
            if(a.first == b.first) return a.second < b.second; // if freq are equal, smaller char comes first
            return a.first > b.first;  // otherwise higher freq first
        });
        string res;
        for(auto &av:v){
            res.append(av.first, av.second);
        }
        return res;
    }
};