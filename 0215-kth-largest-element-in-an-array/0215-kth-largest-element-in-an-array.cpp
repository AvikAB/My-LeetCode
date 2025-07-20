class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto av:nums){
            minHeap.push(av);
            if(minHeap.size()>k) minHeap.pop();  // if the size is exceeds the k then it will remove the smallest ele, cause we want to keep only k-largest ele
        }
        return minHeap.top();
    }
};

// TC: O(nlogk)


// Using sort:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};

// TC: O(nlogn)
