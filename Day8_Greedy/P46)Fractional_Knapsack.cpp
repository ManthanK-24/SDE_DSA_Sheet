
class Solution
{
    public:
    static bool comp(Item a, Item b)
    {
        double x = a.value/(a.weight*1.0);
        double y = b.value/(b.weight*1.0);
        return  x > y;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int cap, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        
        // for(int i=0;i<n;i++)
        // cout<<arr[i].value<<" ";
        // cout<<"#\n";
        
        // for(int i=0;i<n;i++)
        // cout<<arr[i].weight<<" ";
        // cout<<"##\n";
        
        double ans = 0;
        int w = 0;
        
        for(int i=0;i<n;i++)
        {
            if(w < cap)
            {
                
                if(w+arr[i].weight<=cap)
                {
                    ans += (1.0*arr[i].value);
                    w += arr[i].weight;
                }
                else
                {
                    int df = cap - w;
                    double tmp = df*(arr[i].value/(arr[i].weight*1.0));
                    ans += tmp;
                    break;
                }
            }
            else
            break;
        }
        return ans;
    }
        
};
