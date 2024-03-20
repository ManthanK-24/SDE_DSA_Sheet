

class Solution {
public:
    void rotate_clockwise(vector<vector<int>>& matrix) {
        
        // Brute TC:O(n*n) SC:O(n*n) extra
        // Optimized TC:O(n*n) SC:O(1)

        
        reverse(matrix.begin(),matrix.end());
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    }
void rotate_anticlockwise(vector<vector<int>>& matrix) {
        
        // Brute TC:O(n*n) SC:O(n*n) extra
        // Optimized TC:O(n*n) SC:O(1)

        for(int i=0;i<matrix.size();i++)
        {
         reverse(matrix[i].begin(),matrix[i].end());
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    }
};
