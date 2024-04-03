class Solution {
public:
    void solve(int idx,int target,vector<int>&nums, vector<int>& ds, 
               vector<vector<int>>& ans)
    {
      if(idx>=nums.size())
      {
        if(target==0)
        {
            ans.push_back(ds);
            
        }
          return;
      } 
        //pick 
        if(target>=nums[idx])
        {
            ds.push_back(nums[idx]);
            solve(idx,target-nums[idx],nums,ds,ans);
            ds.pop_back();
        }
        
        // not pick
        solve(idx+1,target,nums,ds,ans);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        vector<int> ds;
        solve(0,target,nums,ds,ans);
        
        return ans;
    }
};
class Solution {
public:
    void solve(int idx,int target,vector<int>&nums, vector<int>tmp ,set<vector<int>>& ds)
    {
        int n = nums.size();
        if(idx>=n)return;
        
        if(target==0)
        {
            if(tmp.size()>0)ds.insert(tmp);
            return;
        }
       
        
        // not pick
        solve(idx+1,target,nums,tmp,ds);
        
        //pick 
        if(target>=nums[idx])
        {
            tmp.push_back(nums[idx]);
            solve(idx,target-nums[idx],nums,tmp,ds);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        set<vector<int>> ds;
        solve(0,target,nums,{},ds);
        
        for(auto it=ds.begin();it!=ds.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};
