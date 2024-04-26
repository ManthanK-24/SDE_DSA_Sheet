class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int mxConsecutiveLen = 0;
        
        unordered_map<int,bool> checked, present;
        for(auto x:nums)present[x]=1;
        
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i];
            if(!checked[x] && !present[x-1])
            {
                int cnt = 0;
                while(present[x])
                {
                    checked[x]=1;
                    cnt++;
                    x++;
                }
                mxConsecutiveLen = max(mxConsecutiveLen, cnt);
            }
        }
        return mxConsecutiveLen;
        
    }
};
