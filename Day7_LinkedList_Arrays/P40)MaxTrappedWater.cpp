class Solution { // 0 ms, faster than 100.00%
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int n = height.size(), maxLeft = height[0], maxRight = height[n-1];
        int left = 1, right = n - 2, ans = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ans += maxLeft - height[left];
                left += 1;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ans += maxRight - height[right];
                right -= 1;
            }
        }
        return ans;
    }
};
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
