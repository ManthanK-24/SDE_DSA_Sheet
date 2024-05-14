class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n1, int n2, int k)
    {
        // Two Pointers i & j
        if(n1>n2)return kthElement(arr2,arr1,n2,n1,k);
        
        int n = n1+n2;
        
        int low = max(0,k-n1), high = min(k,n2); // no of elements
        while(low<=high)
        {
            int mid1 = (high+low)>>1;
            
            int mid2 = k - mid1;
            int l1=INT_MIN, l2 = INT_MIN;
            int r1=INT_MAX, r2 = INT_MAX;
            if(mid1<n1)r1 = arr1[mid1];
            if(mid2<n2)r2 = arr2[mid2];
            if(mid1>=1)l1= arr1[mid1-1];
            if(mid2>=1)l2 = arr2[mid2-1];
            
            if(l1<=r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            else if(l1>r2)
            {
                high = mid1-1;
            }
            else
            {
                low = mid1+1;
            }
            
        }
        return 1;
    }
};
