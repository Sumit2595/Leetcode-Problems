class Solution {
public:
    int compress(vector<char>& str) {
        int n=str.size();
        int i=0,j=0;
        while(i<n){
            int count=1;
            str[j++]=str[i++];
            while(i<n && str[j-1] == str[i]){
                count++;
                i++;
            }
            if(count > 1){
                for(auto c:to_string(count)){
                    str[j++]=c;
                }
            }
        }
        return j;
    }
};