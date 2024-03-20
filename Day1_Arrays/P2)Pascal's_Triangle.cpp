class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);

        for(int i=1;i<=n;i++)
        {
            ans[i-1].resize(i);
            for(int j=1;j<=i;j++)
            {
                if(j==1 || j==i)
                {
                   ans[i-1][j-1] = 1;
                }
                else
                {
                   ans[i-1][j-1] = ans[i-2][j-2] + ans[i-2][j-1];   
                }
            }
        }
        return ans;
    }
};
