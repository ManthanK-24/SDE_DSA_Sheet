
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         // Brute TC:O(n*n) SC:O(1)
         // Optimal TC:O(n) SC:O(1)

         int fast = nums[nums[0]], slow = nums[0];
         while(fast!=slow)
         {
            fast = nums[nums[fast]];
            slow = nums[slow];
         }
         fast = 0;
         while(fast!=slow)
         {
            fast = nums[fast];
            slow = nums[slow];
         }
         return fast;
    }
};
