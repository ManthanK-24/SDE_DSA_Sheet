class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        // Brute TC:O(n*n) SC:O(1)
        int ans = 0, cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                ans = max(ans,cnt);
            }
            else
            {
                ans = max(ans,cnt);
                cnt = 0;
            }
            
        }
        return ans;
    }
};
