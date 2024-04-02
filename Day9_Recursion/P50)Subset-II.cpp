class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int> tmp, set<vector<int>>& ds){
        
        int n = nums.size();
        if(idx>=n)return;
        
        if(idx==n-1)
        {
            // not pick 
            sort(tmp.begin(),tmp.end());
            ds.insert(tmp);
            
            // pick
            tmp.push_back(nums[idx]);
            sort(tmp.begin(),tmp.end());
            ds.insert(tmp);
        }
        
        // not pick
        solve(idx+1,nums,tmp,ds);
        
        // pick 
        tmp.push_back(nums[idx]);
        solve(idx+1,nums,tmp,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> ds;
        solve(0,nums,{},ds);
        for(auto it=ds.begin();it!=ds.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;
        
    }
};
