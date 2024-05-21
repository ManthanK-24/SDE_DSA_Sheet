
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(auto vt:kArrays)
    {
        for(auto x:vt)
        pq.push(x);
    }
    while(pq.size()>0)
    {
        ans.push_back(pq.top());
        pq.pop();
    
    }
    return ans;
}
