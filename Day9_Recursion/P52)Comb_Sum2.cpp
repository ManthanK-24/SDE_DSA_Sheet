
class Solution {
public:
    void solve(int idx, int sum, vector<int>& nums, vector<int>& tmp,
               vector<vector<int>>& ans){
        
        if(sum<0)return;
        
        else if(sum == 0)
        {
            if(tmp.size()>0)
            {
                ans.push_back(tmp);
                return;
            }
        }
          
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1])continue;
            
            tmp.push_back(nums[i]);
            solve(i+1,sum-nums[i],nums,tmp,ans);
            tmp.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0,target,nums,ds,ans);
        
        return ans;
    }
};
