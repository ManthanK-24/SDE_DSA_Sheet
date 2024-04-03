
class Solution {
public:
    bool isPalindrome(string s)
    {
        int start = 0, end = s.size()-1;
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return 0;
        }
        return 1;
    }
    void solve(int idx, string s, vector<string>&ds, vector<vector<string>>&ans)
    {
        if(idx==s.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s.substr(idx,i-idx+1)))
            {
                ds.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }  
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> ds;
        solve(0,s,ds,res);
        return res;
    }
};
