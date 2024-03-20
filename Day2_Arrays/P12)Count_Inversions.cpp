long long int merge(long long arr[], long long tmp[], int l,int m,int r)
    {
        int i = l;
        int j = m;
        int k = l;
        long long int invcnt = 0;
        while(i<m && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                tmp[k++] = arr[i++];
            }
            else
            {
                invcnt += m-i;
                tmp[k++] = arr[j++];
            }
        }
        while(i<m)tmp[k++] =arr[i++];
        while(j<=r)tmp[k++] = arr[j++];
        for(int x=l;x<=r;x++)arr[x] = tmp[x];
        return invcnt;
        
    }
    long long int mergeSort(long long arr[], long long tmp[],int l,int r)
    {
        if(l>=r)return 0;
        long long int invcnt = 0;
        int mid = l + (r-l)/2;
        invcnt += mergeSort(arr,tmp,l,mid);
        invcnt += mergeSort(arr,tmp,mid+1,r);
        invcnt += merge(arr,tmp,l,mid+1,r);
        return invcnt;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long tmp[n+1];
        return mergeSort(arr,tmp,0,n-1);
    }
