vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int>>> pq,tmp;
    int n = A.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    pq.push({A[i]+B[n-1],{i,n-1}});
    tmp=pq;
   
    while(!pq.empty() && C--)
    {
        pair<int,pair<int,int>> tp = pq.top();
        int vl = tp.first;
        int x = tp.second.first, y = tp.second.second;
        pq.pop();
        ans.push_back(vl);
        if(y!=0)
        pq.push({A[x]+B[y-1],{x,y-1}});
    }
    return ans;
}
