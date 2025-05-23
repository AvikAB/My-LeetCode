class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size(); i++){
            bool left = (i==0) or (flowerbed[i-1]==0);
            bool right = (i==flowerbed.size()-1) or (flowerbed[i+1]==0);
            if(flowerbed[i]==0 and left and right){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(n<=0) return true;
        else return false;
    }
};