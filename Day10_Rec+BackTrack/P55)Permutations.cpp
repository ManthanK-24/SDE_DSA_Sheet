
class Solution {
public:
    void solve(int idx,vector<int>&nums, vector<vector<int>>&res)
    {
        // TC:O(n!) SC:O(1) extra
        if(idx==nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            
            solve(idx+1,nums,res);
            swap(nums[idx],nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>res;
       // vector<int>ds;
        //vector<int>vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        solve(0,nums,res);
        // permuteHelper(0,vis,nums,ds,res);
        return res;
    }
    void permuteHelper(int cnt, vector<int>&vis,vector<int>& nums,
                       vector<int>&ds,vector<vector<int>>& res)
    {
        int n = nums.size();
         if(cnt==n)
         {
             res.push_back(ds);
             return;
         }
        
        for(int i=0;i<n;i++)
        {
          if(vis[i]==0)
          {
              ds.push_back(nums[i]);
              vis[i]=1;
              permuteHelper(cnt+1,vis,nums,ds,res);
              ds.pop_back();
              vis[i] = 0;
          }            
        }
    }
};
