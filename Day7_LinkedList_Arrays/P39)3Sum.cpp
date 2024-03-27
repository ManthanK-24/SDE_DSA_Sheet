class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int j = i+1;
            int k = n-1;
            int sum = 0 - nums[i];
            while(j<k)
            {
                
                
                if(nums[j]+nums[k]>sum)
                {
                    k--;
                }
                else if(nums[j]+nums[k]<sum)
                {
                    j++;
                }
                else
                {
                    // vector<int> tmp  ={nums[i],nums[j],nums[k]} ;
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    
                    while(j<k && nums[j]==tmp[1])j++;
                    while(j<k && nums[k]==tmp[2])k--;
                }
                
            }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};
