class Solution {
public:
    int merge(vector<int>&a, int s,int e){
        
        int mid = s+(e-s)/2;
        int cnt = 0;
        int i=s, j=mid+1;
        
        while(i<=mid && j<=e)
        {
            if(1ll*a[i]>2ll*a[j])
            {
                cnt += mid-i+1;
                j++;
            }
            else
            {
                i++;
            }
        }
        sort(a.begin()+s,a.begin()+e+1);
        return cnt;
        
    }
    int merge_sort(vector<int>& nums, int s, int e){
        if(s>=e)return 0;
        int mid = s + (e-s)/2;
        int cnt = 0;
        cnt += merge_sort(nums,s,mid);
        cnt += merge_sort(nums,mid+1,e);
        cnt += merge(nums,s,e);
        return cnt;
        
    }
    int reversePairs(vector<int>& nums) {
        // Brute TC:O(n*n) SC:O(1)
        // 
        
        return merge_sort(nums,0,nums.size()-1);
    }
};
