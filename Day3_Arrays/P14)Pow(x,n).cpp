class Solution {
public:
    double myPow(double x, int n) {
        
        // Brute TC:O(n) SC:O(1)
        
         double ans = 1;
        long nn = abs(n);
        while(nn)
        {
            if(nn%2)
            {
                ans = ans * x;
                nn--;
            }
            else
            {
                x = x*x;
                nn = nn/2;
            }
        }
        return n>=0?ans:1/ans;
        
    }
};
