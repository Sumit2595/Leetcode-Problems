class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream str(s);
        string word;
        stack<string>st;
        while(str>>word){
            st.push(word);
        }
        if(st.empty()) return 0;
        return st.top().length();
    }
};