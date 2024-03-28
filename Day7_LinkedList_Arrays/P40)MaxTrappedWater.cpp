class Solution {
public:
    int trap(vector<int>& height) {
        
        // Brute TC:O(n*n) SC:O(1)
        // Improved TC:O(n) SC:O(n)
        int ans = 0;
        int n = height.size();
        vector<int> preMx(n,0), sufMx(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                preMx[i] = height[i];
            }
            else
            {
                preMx[i] = max(preMx[i-1],height[i]);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                sufMx[i] = height[i];
            }
            else
            {
                sufMx[i] = max(sufMx[i+1],height[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            ans += min(preMx[i],sufMx[i])-height[i];
        }
        return ans;
    }
};
