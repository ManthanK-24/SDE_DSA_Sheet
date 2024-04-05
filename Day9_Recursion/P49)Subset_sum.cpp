class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }
};

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
