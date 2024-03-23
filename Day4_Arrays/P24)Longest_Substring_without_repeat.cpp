class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Brute TC:O(n*n) SC:O(1)
        
        int mx = 0;
        set<char> st;
        
        int l = 0;
        for(int r=0;r<s.size();r++)
        {
            
            if(st.find(s[r])!=st.end())
            {
                while(l<r && st.find(s[r])!=st.end())
                {
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            mx = max(mx, r-l+1);
        }
        return mx;
    }
};
