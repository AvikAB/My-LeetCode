class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        int vow = 0, cons = 0;
        for(auto av:word){
            if(av=='#' or av=='$' or av=='@') return false;
            if(av=='a' or av=='A' or av=='E' or av=='e' or av=='I' or av=='i' or av=='o' or av=='O' or av=='U' or av=='u') vow++;
            else if((av>='a' and av<='z') or (av>='A' and av<='Z')) cons++;
        }
        if(vow>=1 and cons>=1) return true;
        return false;
    }
};