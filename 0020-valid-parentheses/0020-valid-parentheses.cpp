class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
    int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(s[i] == ')' && (st.empty() || st.top() != '('))
                    return false;
                if(s[i] == ']' && (st.empty() || st.top() != '['))
                    return false;
                if(s[i] == '}' && (st.empty() || st.top() != '{'))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};