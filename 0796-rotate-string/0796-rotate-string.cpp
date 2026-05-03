class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss = s+s;
        if(s.size()!=goal.size()) return false;
        return ss.find(goal)!=string::npos;
    }
};



// string::npos to help its return type in true false, actually it contains -1