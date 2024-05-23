class Solution {
public:
    bool isValid(string s) {
       
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')st.push(')');
            else if(s[i]=='{')st.push('}');
            else if(s[i]=='[')st.push(']');
            else
            {
                if(st.size()>0)
                {
                    if(st.top()==s[i])st.pop();
                    else
                        return 0;
                }
                else
                    return 0;
            }
        }
        
        return st.size()==0;
    }
};
