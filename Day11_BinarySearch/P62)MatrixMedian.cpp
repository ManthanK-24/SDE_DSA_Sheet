class Solution{   
public:

    int countSmallerThanMid(vector<int> &row, int mid)
    {
      int l = 0, h = row.size() - 1;
      while (l <= h)
      {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
          l = md + 1;
        }
        else
        {
          h = md - 1;
        }
      }
      return l;
    }
    
    int median(vector<vector<int>> &matrix, int m, int n)
    {
        // code here
        
        int low = INT_MAX;
        int high = INT_MIN;
        int need = m*n/2;
        for(int r=0;r<m;r++)low = min(low,matrix[r][0]);
        for(int r=0;r<m;r++)high = max(high,matrix[r][n-1]);
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int x = 0;
            for(int r=0;r<m;r++)
            {
                x += countSmallerThanMid(matrix[r],mid);
            }
            if(x<=need)
            low = mid+1;
            else
            high=mid-1;
            
        }
        return low;
    }
};
