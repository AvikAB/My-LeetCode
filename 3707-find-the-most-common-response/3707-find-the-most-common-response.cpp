class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> um;
        for(const auto &av: responses){
            unordered_set<string> ok;
            for(const auto &ab: av){
                if(ok.find(ab) == ok.end()){
                    ok.insert(ab);
                    um[ab]++;
                }
            }
        }
        int mx = 0;
        string result;
        for(const auto &av: um){
            if(av.second > mx){
                mx = av.second;
                result = av.first;
            } else if(av.second == mx){
                if(av.first < result){
                    result = av.first;
                }
            }
        }
        return result;
    }
};