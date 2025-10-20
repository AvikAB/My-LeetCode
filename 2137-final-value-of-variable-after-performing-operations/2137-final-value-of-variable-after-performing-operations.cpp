class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto av:operations){
            if(av=="X++" or av=="++X") x++;
            else x--;
        }
        return x;
    }
};