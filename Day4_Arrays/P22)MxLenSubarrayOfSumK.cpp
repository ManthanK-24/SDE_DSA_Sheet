//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&ar, int n)
    {   
        // Your code here
        // Brute TC: O(n*n) SC:O(1)
        // Optimal
        int mx = 0;
        unordered_map<int,int> umpIdx;
        int sum = 0 ;
        for(int i=0;i<n;i++)
        {
            sum += ar[i];
            if(sum==0)mx=i+1;
            else
            {
                if(umpIdx.find(sum)!=umpIdx.end())
                {
                    mx = max(mx,i-umpIdx[sum]);
                }
                else
                umpIdx[sum] = i;
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
