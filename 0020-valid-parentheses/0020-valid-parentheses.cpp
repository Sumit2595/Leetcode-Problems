class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(auto s:str){
            if(s=='('){
                st.push('(');
            }
            if(s=='{'){
                st.push('{');
            }
            if(s=='['){
                st.push('[');
            }
            if(s==')'){
                if(st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            if(s=='}'){
                if(st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
            if(s==']'){
                if(st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};