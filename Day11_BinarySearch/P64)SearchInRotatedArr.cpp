class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
      // M1: Sort + BS TC:O(n*logn + logn) SC:O(1)
      // M2: Linear TC:O(n) SC:O(1)
      // M3: Modified BS TC:O(logn) SC:O(1)
        
        int lft = 0, rgt = size(nums)-1;
        
        while(lft<=rgt)
        {
            int mid = lft + (rgt-lft)/2;
            
            if(nums[mid]==target)return mid;
            
                 
            if(nums[lft]<=nums[mid]) // sorted left part
            {
                if(nums[lft]<=target && target<=nums[mid])
                    rgt = mid-1;
                else
                    lft = mid+1;
                    
            }
            else // sorted right part
            {
                if(nums[mid]<=target && target<=nums[rgt])
                    lft = mid+1;
                else
                    rgt = mid-1;
            }
        }
        return -1;
        
    }
};
