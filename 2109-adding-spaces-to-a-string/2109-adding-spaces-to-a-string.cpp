class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int start=0,n=s.length();
        string answer="";
        for(auto space:spaces){
            answer+=s.substr(start,space-start)+" ";
            start=space;
        }
        answer+=s.substr(start);
        return answer;
    }
};