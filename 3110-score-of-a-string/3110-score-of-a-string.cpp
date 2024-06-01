class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int score=0;
        for(int i=1;i<n;i++){
            int a=int(s[i-1]);
            int b=int(s[i]);
            score+=abs(a-b);
        }
        return score;
    }
};