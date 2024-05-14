

bool isPossible(vector<int>& ar, int n, int cows, int minDist)
{
  int cntCows=1;
  int lastPlacedCow = ar[0];
  for(i=1;i<n;i++)
    {
      if(ar[i]-lastPlacedCow >= minDist)
      {
        cntCows++;
        lastPlacedCow = ar[i];
      }
    }
  if(cntCows>=cows)return true;
  return false;
}
int largestMinDist(vector<int>& ar, int n, int cows)
{
   sort(ar.begin(),ar.end();
   int low = 1, high = ar[n-1]-ar[0];
   while(low<=high)
     {
       int mid = (low+high)>>1;
       if(isPossible(ar,n,cows,mid))
         low = mid+1;
       else
         high = mid-1;
     }
  return high;
}
