

class Solution
{
public:
    void solve(int idx,int sum, vector<int>& arr, vector<int>& ans)
    {
        int n = arr.size();
        
        if(idx>=n)return;
        
        if(idx==n-1)
        {
            // not pick
            ans.push_back(sum);
            // pick
            sum += arr[idx];
            ans.push_back(sum);
            return;
        }
        
        // not pick
        solve(idx+1,sum,arr,ans);
        
        // pick
        solve(idx+1,sum+arr[idx],arr,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0,0,arr,ans);
        return ans;
    }
};
