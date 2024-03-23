
int Solution::solve(vector<int> &ar, int k) {
    
    // Brute TC:O(n*n) SC:O(1)
    int cnt=0;
    int x=0;
    unordered_map<int,int> vis;
    
    for(int i=0;i<ar.size();i++)
    {
        x = x^ar[i];
        if(x==k)cnt++;
        if(vis.find(x^k)!=vis.end())
        {
            cnt += vis[x^k];
        }
        vis[x]++;
    }
    return cnt;
}
