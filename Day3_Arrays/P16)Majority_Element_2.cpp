class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        int y = -1, z = -1; 
        int cy = 0, cz = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==y)
            {
                cy++;
            }
            else if(nums[i]==z)
            {
                cz++;
            }
            else if(cy==0)
            {
                y = nums[i];
                cy++;
            }
            else if(cz==0)
            {
                z = nums[i];
                cz++;
            }
            else
            {
                cy--; cz--;
            }
        }
        cy = 0;
        cz = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==y)cy++;
            else if(nums[i]==z)cz++;
        } 
        if(cy> nums.size()/3)ans.push_back(y);
        if(cz> nums.size()/3)ans.push_back(z);
        return ans;
    }
};
