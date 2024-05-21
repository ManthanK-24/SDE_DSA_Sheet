class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
       vector<int> ans; 
        map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        
        for(auto x:nums)mp[x]++;
        
        for(auto [x,cnt]:mp)
        {
            pq.push({cnt,x});
        }
        while(k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
        
    }
};
