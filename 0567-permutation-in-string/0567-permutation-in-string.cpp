class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> s1_freq, s2_freq;
        for(char c:s1){
            s1_freq[c]++;
        }
        int i=0;
        for(int j=0; j<s2.size(); j++){
            s2_freq[s2[j]]++;
            // if window's size exceeds s1.size(), then remove the leftmost char
            if(j-i+1 > s1.size()){
                s2_freq[s2[i]]--;   // decrease the leftmost char's freq count
                if(s2_freq[s2[i]]==0){  // if that leftmost's cnt is overall 0 then remove from the map 
                    s2_freq.erase(s2[i]);
                }
                i++;
            }
            if(s1_freq == s2_freq) return true;
        }
        return false;
    }
};