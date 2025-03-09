class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mxsp = 0;
        for(auto av:sentences){
            int spcnt = count(av.begin(), av.end(), ' ');
            mxsp = max(mxsp, spcnt+1);
        }
        return mxsp;
    }
};