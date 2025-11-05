class Solution {
public:
    #define ll long long int
    ll sum = 0;
    set<pair<int, int>> main;   // contains top-X {freq, ele}
    set<pair<int, int>> sec;    // contains remaining {freq, ele}

    void insertInSet(const pair<int,int>&curr, int x){
        if(main.size()<x or curr > *main.begin()){   // insert in main
            sum += 1LL*curr.first*curr.second;
            main.insert(curr);
            if(main.size()>x){
                auto smallest = *main.begin();
                sum -= 1LL*smallest.first*smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        } else sec.insert(curr);
    }

    void removeFromSet(const pair<int, int>&curr, int x){
        if(main.find(curr)!=main.end()){
            sum -= 1LL*curr.first*curr.second;
            main.erase(curr);
            if(!sec.empty()){
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum += 1LL*largest.first*largest.second;
            }
        } else sec.erase(curr);
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        ll n = nums.size();
        vector<ll>res;
        unordered_map<ll, ll>mp;
        ll i = 0, j = 0;
        while(j<n){
            if(mp[nums[j]]>0){
                removeFromSet({mp[nums[j]], nums[j]}, x);
            }
            mp[nums[j]]++;
            insertInSet({mp[nums[j]], nums[j]}, x);      // {freq, ele}
            if(j-i+1==k){   // shrink the window from left
                res.push_back(sum);
                removeFromSet({mp[nums[i]], nums[i]}, x);    // {freq, ele} of left side
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]], nums[i]}, x);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};