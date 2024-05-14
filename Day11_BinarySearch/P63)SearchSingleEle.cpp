class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
         // M1: Sort TC:O(n*logn) SC:O(1)
        // M2: Map TC:O(n) SC:O(n)
        // M3: Xor TC:O(n) SC:O(1)
        // M4: Binary_Search TC: O(logn) SC: O(1)
        
        int low = 0, high = size(nums)-1;
        
        while(low<high) // Imp
        {
            int mid = low + (high-low)/2;
            
            // left_part
            if((mid%2==0 && nums[mid]==nums[mid+1]) ||
                (mid%2==1 && nums[mid]==nums[mid-1]))
                low = mid+1;
            else
                high = mid;
        }
        return nums[low];
    }
};
