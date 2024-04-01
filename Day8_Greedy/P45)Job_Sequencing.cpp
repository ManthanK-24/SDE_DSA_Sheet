
class Solution 
{
    public:
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int jobs = 0;
        int profit = 0;
        
        sort(arr,arr+n,comp);
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead-1;j>=0;j--)
            {
                if(vis[j]==true)continue;
                else
                {
                    profit += arr[i].profit;
                    jobs++;
                    vis[j] = true;
                    break;
                }
            }
        }
        return {jobs,profit};
        
    } 
};
