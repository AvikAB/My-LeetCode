class Solution {
public:
    #define ll long long int
    ll findcnt(vector<int>&nums1, vector<int>&nums2, ll midProd){
        ll prodcnt = 0;
        ll n = nums2.size();
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]>=0){
                ll l = 0, r = n-1;
                ll m = -1;
                while(l<=r){
                    ll mid = (l+r)/2;
                    ll prod = 1LL*nums1[i]*nums2[mid];
                    if(prod<=midProd){
                        m = mid;
                        l = mid+1;
                    } else r = mid-1;
                }
                prodcnt += (m+1);
            } else {
                ll l = 0, r = n-1;
                ll m = n;
                while(l<=r){
                    ll mid = (l+r)/2;
                    ll prod = 1LL*nums1[i]*nums2[mid];
                    if(prod<=midProd){
                        m = mid;
                        r = mid-1;
                    } else l = mid+1;
                }
                prodcnt += (n-m);
            }
        }
        return prodcnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll res = 0;
        ll l = -1e10;
        ll r = 1e10;
        while(l<=r){
            ll midProd = (l+r)/2;
            ll cnt = findcnt(nums1, nums2, midProd);
            if(cnt>=k){
                res = midProd;
                r = midProd-1;
            } else l = midProd+1;
        }
        return res;
    }
};