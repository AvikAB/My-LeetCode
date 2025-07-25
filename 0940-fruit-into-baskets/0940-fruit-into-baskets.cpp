class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>um;
        int l = 0, ans = 0;
        for(int r=0; r<fruits.size(); r++){
            um[fruits[r]]++;
            while(um.size()>2){   // if the bucket size is more than 2 then remove the first one, if the first one's freq is 0 then remove it permanently
                um[fruits[l]]--;
                if(um[fruits[l]]==0) um.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
    return ans;
    }
};