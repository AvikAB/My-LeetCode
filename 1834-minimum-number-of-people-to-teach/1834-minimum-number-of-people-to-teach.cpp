class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> needTeaching;
        for(auto friends:friendships){
            // here, friendships are 1-based & languages are 0-based, so I need to convert this into 0-based indexing thats why -1
            int u = friends[0]-1;
            int v = friends[1]-1;
            unordered_set<int> langs(languages[u].begin(), languages[u].end());  //store all known languages of 1st friend (u)
            bool ok = false;
            // find common langs betwn u & v
            for(int lang:languages[v]){
                if(langs.count(lang)){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                needTeaching.insert(u);
                needTeaching.insert(v);
            }
        }
        if(needTeaching.size()==0) return 0;

        // Find max known langs among needTeaching users
        vector<int> language(n+1, 0);
        int mostKnownLang = 0;
        for(int user:needTeaching){
            for(int lang:languages[user]){
                language[lang]++;
                mostKnownLang = max(mostKnownLang, language[lang]);
            }
        }
        return needTeaching.size() - mostKnownLang;
    }
};