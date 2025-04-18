class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(i!=j and arr[i] == 2*arr[j] or arr[j] == 2*arr[i]) return true;
            }
        }
        return false;
    }
};