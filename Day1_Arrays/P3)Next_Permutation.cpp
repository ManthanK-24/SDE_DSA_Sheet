
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int k = -1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                k = i;
                break;
            }
        }
        if(k==-1)
        {
            sort(nums.begin(),nums.end());
        }
        else
        {
            int j = -1;
            for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]>nums[k])
                {
                    j = i;
                    break;
                }
            }
            swap(nums[k],nums[j]);
           reverse(nums.begin()+k+1,nums.end());
        }
    }
};
