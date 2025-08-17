class Solution {
public:
    string interpret(string command) {
        string ans = "";
        char prev;
        for(char av: command){
            if(av=='G' or av=='a' or av=='l') ans.push_back(av);
            else if(av==')' and prev=='(') ans.push_back('o');
            prev = av;
        }
        return ans;
    }
};