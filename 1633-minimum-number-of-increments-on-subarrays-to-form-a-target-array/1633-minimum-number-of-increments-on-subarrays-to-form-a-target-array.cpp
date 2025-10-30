class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int sum = target[0];   // start with 1st ele
        for(int i=1; i<target.size(); i++){
            if(target[i] > target[i-1]){
                sum += target[i]-target[i-1];   // add only when value increases or curr > prev
            }
        }
        return sum;
    }
};