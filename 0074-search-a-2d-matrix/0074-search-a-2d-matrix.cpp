class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0, high = row*col-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int midRow = mid/col, midCol = mid%col;
            int ele = matrix[midRow][midCol];
            if(ele==target) return true;
            else if(ele<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};