class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        int i=0,ans=1;
        int mask=0;
        while(i<n){
            int pos=(s[i]-'a');
            if(mask & (1<<pos)){
                mask=0;
                ans++;
            }
            mask|=(1<<pos);
            i++;
        }
        return ans;
    }
};