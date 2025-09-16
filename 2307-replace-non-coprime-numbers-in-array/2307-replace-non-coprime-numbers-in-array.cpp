class Solution {
public:
    #define ll long long
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        ll n = nums.size();
        stack<ll>s;
        s.push(nums[0]);
        for(int i=1; i<n; i++){
            ll currEle = nums[i];
            while(!s.empty()){
                auto it = s.top();
                if(__gcd(it, currEle)>1){   // checking non-coprime
                    s.pop();
                    currEle = std::lcm(it, currEle);
                } else break;
            }
            s.push(currEle);
        }
        vector<int> ans;
        while(!s.empty()){
            auto it = s.top();
            s.pop();
            ans.push_back(int(it));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};