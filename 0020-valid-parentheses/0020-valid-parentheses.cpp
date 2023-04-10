class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(auto s:str){
            if(st.empty()){
                st.push(s);
            } else if(s==')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                } else{
                    return false;
                }
            } else if(s=='}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                } else{
                    return false;
                }
            } else if(s==']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                } else{
                    return false;
                }
            } else{
                st.push(s);
            }
        }
        return st.empty();
    }
};