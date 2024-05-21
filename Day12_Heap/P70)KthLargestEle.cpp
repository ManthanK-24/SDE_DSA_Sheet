class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        for(auto x:nums)pq.push(x);
        int sz = k-1;
        while(sz)
        {
            pq.pop();
            sz--;
        }
        return pq.top();
    }
};
