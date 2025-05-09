class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto av:words){
            string ans = av;   // store string from the array
            reverse(ans.begin(), ans.end());  // reverse that string
            if(ans==av) return ans;  // check if its palindrome or not
        }
        return "";
    }
};