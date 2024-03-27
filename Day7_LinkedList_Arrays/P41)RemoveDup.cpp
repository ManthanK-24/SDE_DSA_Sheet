class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int,int> freq;
        
        int j = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(freq[nums[i]]==0)
            {
               freq[nums[i]]++;
                nums[j++] = nums[i];
            }
            
        }
        
        return freq.size();
    }
};
