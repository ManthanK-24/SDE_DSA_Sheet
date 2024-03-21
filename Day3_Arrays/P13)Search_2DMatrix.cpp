
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Brute TC:O(m*n) SC:O(1)
        // 
        int m = matrix.size(), n = matrix[0].size();
        int row_s = 0, row_e = m-1;
        int col_s = 0, col_e = n-1;
        int row = -1, col = -1; 
        while(row_s<row_e)
        {
            int mid = row_s + (row_e-row_s)/2;
            if(matrix[mid][col_s]>= target && target<=matrix[mid][col_e])
            {
               row = mid;
               break;
            }
            else if(target > matrix[mid][col_e])
            {
                row_s = mid + 1;
            }
            else if(target < matrix[mid][col_s])
            {
                row_e = mid-1;
            }
        } 
        if(row==-1)return 0;

        while(col_s<col_e)
        {
            int mid = col_s + (col_e-col_s)/2;
            if(matrix[row][mid]==target)
            {
                col = mid;
                break;
            }
            else if(matrix[row][mid]>target)
            {
                col_e = mid - 1; 
            }
            else if(matrix[row][mid]<target)
            {
                col_s = mid + 1;
            }
        }
        if(col==-1)return 0;
        return 1;
    }
};
