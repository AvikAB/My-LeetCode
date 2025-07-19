class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for(const auto &curr: folder){
            if(ans.empty()) ans.push_back(curr);
            else {
                const string &prev = ans.back();
                if(curr.find(prev)==0 and curr.size()>prev.size() and curr[prev.size()]=='/') continue;
                else ans.push_back(curr);
            }
        }
        return ans;
    }
};