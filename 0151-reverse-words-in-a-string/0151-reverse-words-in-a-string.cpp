class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string word;
        stack<string>st;
        string ans="";
        while(str >> word){
            cout<<word<<" ";
            st.push(word);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};