

#include<bits/stdc++.h>
using namespace std;

int mul(double x, int n)
{
     int ans = 1;
     long long nn = abs(n);
     while(nn>0)
       {
          if(nn%2)
          {
            ans = ans * x;
            nn--;
          }
          else
          {
            x = x*x;
            nn=nn/2;
          }
       }
      return ans;
}
int getNthRoot(int n, int m)
{
    int low = 1, high = m;
    while(low<=high)
    {
      int mid = low + (high-low)/2;
      int val = mul(mid,n);
      if(val>m)
      {
        high = mid-1;
      }
      else if(val<m)
      {
        low = mid+1;
      }
      else
      {
         return mid;  
      }
    }
  return -1;
}


int main()
{
  int n,m;
  n = 3; m = 27;
  getNthroot(n,m);
  return 0;
}
