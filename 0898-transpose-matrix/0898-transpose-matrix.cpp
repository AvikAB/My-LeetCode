// This is using extra space:

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[j][i] = matrix[i][j];
            }
        }
        return mat;
    }
};


// This is without any extra space:
class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();  // square matrix n x n
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){  // start from i+1
                swap(matrix[i][j], matrix[j][i]);  // swap across main diagonal, Swapping matrix[i][i] with itself is unnecessary. Thats why j = i+1
            }
        }
    }
};
// Here, Swap function only works for in-place
