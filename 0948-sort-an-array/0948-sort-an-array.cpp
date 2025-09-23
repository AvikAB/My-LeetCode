class Solution {
public:
    void mergeSort(vector<int>&nums, int n, int low, int mid, int high){
        int p = low;      // 1st part pointer
        int q = mid+1;    // 2nd part pointer
        int len = high-low+1;
        vector<int>v(len);
        int k = 0;   // vector's pointer
        for(int i=low; i<=high; i++){
            if(p > mid){          // 1st ending condition
                v[k] = nums[q];
                k++, q++;
            } else if(q > high){   // 2nd ending condition
                v[k] = nums[p];
                k++, p++;
            } else if(nums[p] <= nums[q]){   // normal ascending sort condition
                v[k] = nums[p];
                k++, p++;
            } else {
                v[k] = nums[q];
                k++, q++;
            }
        }
        // taking all vector's elements in old array
        k = 0;
        for(int i=low; i<=high; i++){
            nums[i] = v[k];
            k++;
        }
    }

    void merge(vector<int>&nums, int n, int low, int high){
        if(low==high) return;   // base case
        int mid = low+((high-low)/2);
        merge(nums, n, low, mid);    // recursive call
        merge(nums, n, mid+1, high); // recursive call
        mergeSort(nums, n, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        merge(nums, n, low, high);
        return nums;
    }
};