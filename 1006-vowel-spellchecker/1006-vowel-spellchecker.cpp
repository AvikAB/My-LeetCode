class Solution {
public:
    unordered_set<string> exactSet;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowMap;

    string toLower(string &s){
        string ans = s;
        for(char &c: ans){  // here, use &c, if i change c then its directly changed to ans
            c = tolower(c);
        }
        return ans;
    }

    string isVowel(string &s){
        string ans = s;
        for(char &c:ans){
            if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u'){
                c = '#';
            }
        }
        return ans;
    }

    string check(string &query){
        // first check in exactSet
        if(exactSet.count(query)) return query;

        //case error check
        string lowercase = toLower(query);
        if(caseMap.count(lowercase)) return caseMap[lowercase];        

        // vowel error check
        string vowelcase = isVowel(lowercase);
        if(vowMap.count(vowelcase)) return vowMap[vowelcase];

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMap.clear();
        vowMap.clear();

        for(string word: wordlist){
            exactSet.insert(word);

            string lowerCase = toLower(word);
            if(caseMap.find(lowerCase)==caseMap.end()){  // if not present in caseMap then put it
                caseMap[lowerCase] = word;
            }

            string vowelCase = isVowel(lowerCase);
            if(vowMap.find(vowelCase)==vowMap.end()){  // if not present in vowMap then put it
                vowMap[vowelCase] = word;    // use vowelCase as the key, let, koop -> k##p, k##p will be key & koop will be val
            }
        }
        vector<string> res;
        for(string &query: queries){
            res.push_back(check(query));
        }
        return res;
    }
};